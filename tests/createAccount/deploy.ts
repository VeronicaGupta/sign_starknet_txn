import { Account, ec, json, stark, hash, CallData } from "starknet";
import { Provider, constants } from "provider"; // Adjust the import path as needed

//**************** Compute Address*************************************************
// connect provider
const providerInstance = new Provider({ sequencer: { network: constants.NetworkName.SN_GOERLI } });

// //new Argent X account v0.2.3
const argentXproxyClassHash = "0x25ec026985a3bf9d0cc1fe17326b245dfdc3ff89b8fde106542a3ea56c5a918";
const argentXaccountClassHash = "0x033434ad846cdd5f23eb73ff09fe6fddd568284a0fb7d1be20ee482f044dabe2";

// Generate public and private key pair.
const privateKeyAX = "0x005394a57e58341186ac9ec39d29c7ecaf0ba43463e448c3613c22eb40499516"; //stark.randomAddress();
console.log('AX_ACCOUNT_PRIVATE_KEY=', privateKeyAX);
const starkKeyPubAX = ec.starkCurve.getStarkKey(privateKeyAX);
console.log('AX_ACCOUNT_PUBLIC_KEY=', starkKeyPubAX);

// Calculate future address of the ArgentX account
const AXproxyConstructorCallData = CallData.compile({
    implementation: argentXaccountClassHash,
    selector: hash.getSelectorFromName("initialize"),
    calldata: CallData.compile({ signer: starkKeyPubAX, guardian: "0" }),
});
const AXcontractAddress = hash.calculateContractAddressFromHash(
    starkKeyPubAX,
    argentXproxyClassHash,
    AXproxyConstructorCallData,
    0
);
console.log('Precalculated account address=', AXcontractAddress);


// ****************Deployment of the new account*************************************************
const accountAX = new Account(providerInstance, AXcontractAddress, privateKeyAX);

const deployAccountPayload = {
    classHash: argentXproxyClassHash,
    constructorCalldata: AXproxyConstructorCallData,
    contractAddress: AXcontractAddress,
    addressSalt: starkKeyPubAX };

const { transaction_hash: AXdAth, contract_address: AXcontractFinalAddress } = await accountAX.deployAccount(deployAccountPayload);
console.log('✅ ArgentX wallet deployed at:', AXcontractFinalAddress);

console.log("\n")
