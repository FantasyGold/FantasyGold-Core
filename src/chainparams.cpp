// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparams.h>

#include <chainparamsseeds.h>
#include <consensus/merkle.h>
#include <consensus/consensus.h>
#include <tinyformat.h>
#include <util/system.h>
#include <util/strencodings.h>
#include <util/convert.h>
#include <versionbitsinfo.h>

#include <assert.h>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

///////////////////////////////////////////// // fantasygold
#include <libdevcore/SHA3.h>
#include <libdevcore/RLP.h>
#include "arith_uint256.h"
/////////////////////////////////////////////

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 00 << 488804799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    genesis.hashStateRoot = uint256(h256Touint(dev::h256("e965ffd002cd6ad0e2dc402b8044de833e06b23127ea8c3d80aec91410771495"))); // fantasygold
    genesis.hashUTXORoot = uint256(h256Touint(dev::sha3(dev::rlp("")))); // fantasygold
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "May 17, 2019 Google has been tracking nearly everything you buy";
    const CScript genesisOutputScript = CScript() << ParseHex("04fb2f78cde51535a533deadcb0f012f84a8ee7f4c9c458b566f7189b58ffae73a01a47e85ba11dbec73dc75576a46110dc16deb4a1028e9cd45197e91322c052a") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block?
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 985500; // fantasygold halving every 4 years
        consensus.BIP16Exception = uint256S("0x00000000c2d6c00523c13656709668b65ab59c80c18c33ef22f2c5824542ee8c");
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256S("0x00000000c2d6c00523c13656709668b65ab59c80c18c33ef22f2c5824542ee8c");
        consensus.BIP65Height = 0; // 000000000000000004c2b624ed5d7756c508d90fd0da2c7c679febfa6c4735f0
        consensus.BIP66Height = 0; // 00000000000000000379eaa19dce8c9b722d46ae6a57c2f1a988119488b50931
        //new
		    consensus.CSVHeight = 0; // 000000000000000004a1b34462cb8aeebd5799177f7a29cf28f2d1961716b5b5
        consensus.SegwitHeight = 0; // 0000000000000000001c8018d9cb3b742ef25114f27563e3fc4a1902167f9893
        consensus.MinBIP9WarningHeight = 0; // segwit activation height + miner confirmation window
        consensus.QIP5Height = 200000;
        consensus.QIP6Height = 200000;
        consensus.QIP7Height = 200000;
        consensus.QIP9Height = 200000;
		
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        //new
		consensus.QIP9PosLimit = uint256S("0000000000001fffffffffffffffffffffffffffffffffffffffffffffffffff"); // The new POS-limit activated after QIP9
        
		consensus.nPowTargetTimespan = 16 * 60; // 16 minutes
        //new
		consensus.nPowTargetTimespanV2 = 4000;
        
		consensus.nPowTargetSpacing = 2 * 64;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = true;
        consensus.fPoSNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 1916; // 95% of 2016
        consensus.nMinerConfirmationWindow = 2016; // nPowTargetTimespan / nPowTargetSpacing
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x000000000000000000000000000000000000000000000002ea72da07ce28fa4e"); // fantasygold

        // By default assume that the signatures in ancestors of this block are valid.
       // consensus.defaultAssumeValid = uint256S("0x0000f286807cd4035cadfe039e4691f4960794344640c234abeae3544310fb9c"); // block heightconsensus.defaultAssumeValid = uint256S("0x0000f286807cd4035cadfe039e4691f4960794344640c234abeae3544310fb9c"); // block height

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
        pchMessageStart[0] = 0xd2;
        pchMessageStart[1] = 0xbd;
        pchMessageStart[2] = 0xf5;
        pchMessageStart[3] = 0xa1;
        nDefaultPort = 57814;
        nPruneAfterHeight = 100000;
        m_assumed_blockchain_size = 8;
        m_assumed_chain_state_size = 1;

        genesis = CreateGenesisBlock(1562129547, 1950712874, 0x1d00ffff, 1, 50 * COIN);
        
        consensus.hashGenesisBlock = genesis.GetHash();           
       

	

        assert(consensus.hashGenesisBlock == uint256S("0x00000000c2d6c00523c13656709668b65ab59c80c18c33ef22f2c5824542ee8c"));
        assert(genesis.hashMerkleRoot == uint256S("0x445f47dbb97c4ccad83a131158776d06dcd0bf85ba26d2f5fb7845b5cd7311e8"));

        // Note that of those which support the service bits prefix, most only support a subset of
        // possible options.
        // This is fine at runtime as we'll fall back to using them as a oneshot if they don't support the
        // service bits we want, but we should get them updated to support all service bits wanted by any
        // release ASAP to avoid it where possible.
        vSeeds.emplace_back("fgc1.fantasygold.io"); // FantasyGold mainnet
        vSeeds.emplace_back("fgc2.fantasygold.io"); // FantasyGold mainnet

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,35);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,38);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,138);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x08, 0xB8, 0xD2, 0x3E};
        base58Prefixes[EXT_SECRET_KEY] = {0x02, 0xA7, 0xF1, 0x4B};

        bech32_hrp = "fg";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        m_is_test_chain = false;

        checkpointData = {
            {
                
                {0, uint256S("0x00000000c2d6c00523c13656709668b65ab59c80c18c33ef22f2c5824542ee8c")},
				{8800, uint256S("0x00004c2cf34f5d15ce61868d230c3c4cbc50df8feca03724e1c6d1170e8eecd6")}, //last PoW block
                {10000, uint256S("0xa5b4947a26cbde596eb52a015a3be0733bf6192baedcf7d039ecf66a9d4672a7")},
                {150000, uint256S("0x2a6d96119a9ab6d88f49c837c2eedb28d62e437134a055615718adea9884fe60")},
            }
        };

        chainTxData = ChainTxData{
            // Data as of block c55e483f1c035d2f17dc4b9b33c530701885409e289d97ca64208b1b6d8e9f14 (height 160847)
        	1584048384, // * UNIX timestamp of last known number of transactions //check this timestamp?
			314022, // * total number of transactions between genesis and that timestamp
                            //   (the tx=... number in the SetBestChain debug.log lines)
			0.01408863155086456 // * estimated number of transactions per second after that timestamp
        };

        /* disable fallback fee on mainnet */
        //m_fallback_fee_enabled = false;

        consensus.nLastPOWBlock = 8800;
        consensus.nMPoSRewardRecipients = 10;
        consensus.nFirstMPoSBlock = consensus.nLastPOWBlock + 
                                    consensus.nMPoSRewardRecipients + 
                                    COINBASE_MATURITY;

        consensus.nFixUTXOCacheHFHeight = 100000; //new
        consensus.nEnableHeaderSignatureHeight = 100000; 
        consensus.nCheckpointSpan = COINBASE_MATURITY; //new
    }
};

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 985500; // fantasygold halving every 4 years
        consensus.BIP16Exception = uint256S("0x00000000f4df2cfa0dc2cb56758f5a54351d8a2c2d715278e876f448c3e23506");
        consensus.BIP34Height = 0;
        consensus.BIP34Hash = uint256S("0x00000000f4df2cfa0dc2cb56758f5a54351d8a2c2d715278e876f448c3e23506");
        consensus.BIP65Height = 0; // 0x00000000f4df2cfa0dc2cb56758f5a54351d8a2c2d715278e876f448c3e23506
        consensus.BIP66Height = 0; // 0x00000000f4df2cfa0dc2cb56758f5a54351d8a2c2d715278e876f448c3e23506
        consensus.CSVHeight = 432; // 00006b24f0bb1e286d6384ca10dc49be4c8740d8b9389934f16bd60f5e1073b3
        consensus.SegwitHeight = 432; // 00006b24f0bb1e286d6384ca10dc49be4c8740d8b9389934f16bd60f5e1073b3
        consensus.MinBIP9WarningHeight = 576; // segwit activation height + miner confirmation window
        consensus.QIP5Height = 1880;
        consensus.QIP6Height = 1880;
        consensus.QIP7Height = 1880;
        consensus.QIP9Height = 1880;
        consensus.powLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("0000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.QIP9PosLimit = uint256S("0000000000001fffffffffffffffffffffffffffffffffffffffffffffffffff"); // The new POS-limit activated after QIP9
        consensus.nPowTargetTimespan = 16 * 60; // 16 minutes
        consensus.nPowTargetTimespanV2 = 4000;
        consensus.nPowTargetSpacing = 2 * 64;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = true;
        consensus.fPoSNoRetargeting = false;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains - 1512
        consensus.nMinerConfirmationWindow = 144; // nPowTargetTimespan / nPowTargetSpacing - 2016
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 1199145601; // January 1, 2008
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = 1230767999; // December 31, 2008

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0000000000000000000000000000000000000000000000001bb0211d6a722c08"); // fantasygold

        // By default assume that the signatures in ancestors of this block are valid.
        //consensus.defaultAssumeValid = uint256S("0x00"); // 320000
        consensus.defaultAssumeValid = uint256S("0x76a6f3fc227d341f52be6585f5aa37b54df89d931cbde811fd7be048dcc12f93"); // block heightc //881

        pchMessageStart[0] = 0x0c;
        pchMessageStart[1] = 0x33;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0xf0;
        nDefaultPort = 58806;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 2;
        m_assumed_chain_state_size = 1;

        genesis = CreateGenesisBlock(1561661716, 895853871, 0x1d00ffff, 1, 50 * COIN);
        
        consensus.hashGenesisBlock = genesis.GetHash();
        
        assert(consensus.hashGenesisBlock == uint256S("0x00000000f4df2cfa0dc2cb56758f5a54351d8a2c2d715278e876f448c3e23506"));
        assert(genesis.hashMerkleRoot == uint256S("0x445f47dbb97c4ccad83a131158776d06dcd0bf85ba26d2f5fb7845b5cd7311e8"));

        vFixedSeeds.clear();
        vSeeds.clear();
        // nodes with support for servicebits filtering should be at the top
        vSeeds.emplace_back(testnet.fantasygold.io); // FantasyGold testnet

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,95);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,88);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,140);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x08, 0x45, 0xC3, 0xF8};
        base58Prefixes[EXT_SECRET_KEY] = {0x03, 0x65, 0x43, 0x88};

        bech32_hrp = "tf";

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        m_is_test_chain = true;


        checkpointData = {
            {
                { 0, uint256S("00000000f4df2cfa0dc2cb56758f5a54351d8a2c2d715278e876f448c3e23506")},
                { 1300, uint256S("76a6f3fc227d341f52be6585f5aa37b54df89d931cbde811fd7be048dcc12f93")}, //last PoW block
                
            }
        };

        chainTxData = ChainTxData{
            // Data as of block 3afbc669b40f3a669d742bc835fc93b3c59910ce2fb8e10ca89465ede91b360e (height 1300)
        	1583886672,
			0,
			0.027
        };

        /* enable fallback fee on testnet */
        //m_fallback_fee_enabled = true;

        consensus.nLastPOWBlock = 880;
        consensus.nMPoSRewardRecipients = 10;
        consensus.nFirstMPoSBlock = consensus.nLastPOWBlock + 
                                    consensus.nMPoSRewardRecipients + 
                                    COINBASE_MATURITY;

        consensus.nFixUTXOCacheHFHeight = 1550; //new
        consensus.nEnableHeaderSignatureHeight = 881;
        consensus.nCheckpointSpan = COINBASE_MATURITY; //new
    }
};

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    explicit CRegTestParams(const ArgsManager& args) { //changed
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 150;
        consensus.BIP16Exception = uint256S("0x3687ba41c0a4621c646ca11ed757568373e51c6e51ba20076e9d39bb58404bb4");
        consensus.BIP34Height = 0; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests) // activate for fantasygold
        consensus.BIP34Hash = uint256S("0x3687ba41c0a4621c646ca11ed757568373e51c6e51ba20076e9d39bb58404bb4");
        consensus.BIP65Height = 0; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 0; // BIP66 activated on regtest (Used in rpc activation tests)
		consensus.CSVHeight = 432; // CSV activated on regtest (Used in rpc activation tests)
        consensus.SegwitHeight = 0; // SEGWIT is always activated on regtest unless overridden
        consensus.MinBIP9WarningHeight = 0;
        consensus.QIP5Height = 0;
        consensus.QIP6Height = 0;
        consensus.QIP7Height = 0;
        consensus.QIP9Height = 0;
		
        consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.posLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.QIP9PosLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"); // The new POS-limit activated after QIP9
        consensus.nPowTargetTimespan = 16 * 60; // 16 minutes (960 = 832 + 128; multiplier is 832)
        consensus.nPowTargetTimespanV2 = 4000;
        consensus.nPowTargetSpacing = 2 * 64;
        consensus.fPowAllowMinDifficultyBlocks = true;
        consensus.fPowNoRetargeting = true;
        consensus.fPoSNoRetargeting = true;
        consensus.nRuleChangeActivationThreshold = 108; // 75% for testchains
        consensus.nMinerConfirmationWindow = 144; // Faster than normal for regtest (144 instead of 2016)
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].bit = 28;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nStartTime = 0;
        consensus.vDeployments[Consensus::DEPLOYMENT_TESTDUMMY].nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;

        // The best chain should have at least this much work.
        consensus.nMinimumChainWork = uint256S("0x00");

        // By default assume that the signatures in ancestors of this block are valid.
        consensus.defaultAssumeValid = uint256S("0x00");

        pchMessageStart[0] = 0xbd;
        pchMessageStart[1] = 0xa3;
        pchMessageStart[2] = 0xc2;
        pchMessageStart[3] = 0xf4;
        nDefaultPort = 59806;
        nPruneAfterHeight = 1000;
        m_assumed_blockchain_size = 0;
        m_assumed_chain_state_size = 0;

        UpdateActivationParametersFromArgs(args);

        genesis = CreateGenesisBlock(1561662141, 3, 0x207fffff, 1, 50 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x3687ba41c0a4621c646ca11ed757568373e51c6e51ba20076e9d39bb58404bb4"));
        assert(genesis.hashMerkleRoot == uint256S("0x445f47dbb97c4ccad83a131158776d06dcd0bf85ba26d2f5fb7845b5cd7311e8"));

        vFixedSeeds.clear(); //!< Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //!< Regtest mode doesn't have any DNS seeds.

        fDefaultConsistencyChecks = true;
        fRequireStandard = true;
        m_is_test_chain = true;

        checkpointData = {
            {
                {0, uint256S("3687ba41c0a4621c646ca11ed757568373e51c6e51ba20076e9d39bb58404bb4")},
            }
        };

        chainTxData = ChainTxData{
            0,
            0,
            0
        };
        consensus.nLastPOWBlock = 0x7fffffff;
        consensus.nMPoSRewardRecipients = 10;
        consensus.nFirstMPoSBlock = 8800;
		//consensus.nEnableHeaderSignatureHeight = 8801;
        consensus.nFixUTXOCacheHFHeight=0;
        consensus.nEnableHeaderSignatureHeight = 0;
        consensus.nCheckpointSpan = COINBASE_MATURITY;
        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,95);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,88);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,140);
        base58Prefixes[EXT_PUBLIC_KEY] = {0x08, 0x45, 0xC3, 0xF8};
        base58Prefixes[EXT_SECRET_KEY] = {0x03, 0x65, 0x43, 0x88};

        bech32_hrp = "fgct";
	}

	/**
     * Allows modifying the Version Bits regtest parameters.
     */
    void UpdateVersionBitsParameters(Consensus::DeploymentPos d, int64_t nStartTime, int64_t nTimeout)
    {
        consensus.vDeployments[d].nStartTime = nStartTime;
        consensus.vDeployments[d].nTimeout = nTimeout;
    }
    void UpdateActivationParametersFromArgs(const ArgsManager& args);
};

void CRegTestParams::UpdateActivationParametersFromArgs(const ArgsManager& args)
{
    if (gArgs.IsArgSet("-segwitheight")) {
        int64_t height = gArgs.GetArg("-segwitheight", consensus.SegwitHeight);
        if (height < -1 || height >= std::numeric_limits<int>::max()) {
            throw std::runtime_error(strprintf("Activation height %ld for segwit is out of valid range. Use -1 to disable segwit.", height));
        } else if (height == -1) {
            LogPrintf("Segwit disabled for testing\n");
            height = std::numeric_limits<int>::max();
        }
        consensus.SegwitHeight = static_cast<int>(height);
    }
     
    if (!args.IsArgSet("-vbparams")) return;

    for (const std::string& strDeployment : args.GetArgs("-vbparams")) {
        std::vector<std::string> vDeploymentParams;
        boost::split(vDeploymentParams, strDeployment, boost::is_any_of(":"));
        if (vDeploymentParams.size() != 3) {
            throw std::runtime_error("Version bits parameters malformed, expecting deployment:start:end");
        }
        int64_t nStartTime, nTimeout;
        if (!ParseInt64(vDeploymentParams[1], &nStartTime)) {
            throw std::runtime_error(strprintf("Invalid nStartTime (%s)", vDeploymentParams[1]));
        }
        if (!ParseInt64(vDeploymentParams[2], &nTimeout)) {
            throw std::runtime_error(strprintf("Invalid nTimeout (%s)", vDeploymentParams[2]));
        }
        bool found = false;
        for (int j=0; j < (int)Consensus::MAX_VERSION_BITS_DEPLOYMENTS; ++j) {
            if (vDeploymentParams[0] == VersionBitsDeploymentInfo[j].name) {
                UpdateVersionBitsParameters(Consensus::DeploymentPos(j), nStartTime, nTimeout);
                found = true;
                LogPrintf("Setting version bits activation parameters for %s to start=%ld, timeout=%ld\n", vDeploymentParams[0], nStartTime, nTimeout);
                break;
            }
        }
        if (!found) {
            throw std::runtime_error(strprintf("Invalid deployment (%s)", vDeploymentParams[0]));
        }
    }
    }

/**
 * Regression network parameters overwrites for unit testing
 */
class CUnitTestParams : public CRegTestParams
{
public:
    explicit CUnitTestParams(const ArgsManager& args)
    : CRegTestParams(args)
    {
        // Activate the the BIPs for regtest as in Bitcoin
        consensus.BIP16Exception = uint256();
        consensus.BIP34Height = 100000000; // BIP34 has not activated on regtest (far in the future so block v1 are not rejected in tests)
        consensus.BIP34Hash = uint256();
        consensus.BIP65Height = 1351; // BIP65 activated on regtest (Used in rpc activation tests)
        consensus.BIP66Height = 1251; // BIP66 activated on regtest (Used in rpc activation tests)
        consensus.QIP6Height = 1000; //new
        consensus.QIP7Height = 0; // QIP7 activated on regtest --new

        // FGC have 500 blocks of maturity, increased values for regtest in unit tests in order to correspond with it
        consensus.nSubsidyHalvingInterval = 750;
        consensus.nRuleChangeActivationThreshold = 558; // 75% for testchains
        consensus.nMinerConfirmationWindow = 744; // Faster than normal for regtest (744 instead of 2016)
        consensus.nCheckpointSpan = 1000; // Increase the check point span for the reorganization tests from 500 to 1000
    }
};

static std::unique_ptr<const CChainParams> globalChainParams;

const CChainParams &Params() {
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<const CChainParams> CreateChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CChainParams>(new CMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CChainParams>(new CTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CChainParams>(new CRegTestParams(gArgs));
    else if (chain == CBaseChainParams::UNITTEST)
        return std::unique_ptr<CChainParams>(new CUnitTestParams(gArgs));
    throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    globalChainParams = CreateChainParams(network);
}

std::string CChainParams::EVMGenesisInfo(dev::eth::Network network) const
{
    std::string genesisInfo = dev::eth::genesisInfo(network);
    ReplaceInt(consensus.QIP7Height, "QIP7_STARTING_BLOCK", genesisInfo);
    ReplaceInt(consensus.QIP6Height, "QIP6_STARTING_BLOCK", genesisInfo);
    return genesisInfo;
}

std::string CChainParams::EVMGenesisInfo(dev::eth::Network network, int nHeight) const
{
    std::string genesisInfo = dev::eth::genesisInfo(network);
    ReplaceInt(nHeight, "QIP7_STARTING_BLOCK", genesisInfo);
    ReplaceInt(nHeight, "QIP6_STARTING_BLOCK", genesisInfo);
    return genesisInfo;
}

void CChainParams::UpdateOpSenderBlockHeight(int nHeight)
{
    consensus.QIP5Height = nHeight;
}

void UpdateOpSenderBlockHeight(int nHeight)
{
    const_cast<CChainParams*>(globalChainParams.get())->UpdateOpSenderBlockHeight(nHeight);
}

void CChainParams::UpdateBtcEcrecoverBlockHeight(int nHeight)
{
    consensus.QIP6Height = nHeight;
}

void UpdateBtcEcrecoverBlockHeight(int nHeight)
{
    const_cast<CChainParams*>(globalChainParams.get())->UpdateBtcEcrecoverBlockHeight(nHeight);
}

void CChainParams::UpdateConstantinopleBlockHeight(int nHeight)
{
    consensus.QIP7Height = nHeight;
}

void UpdateConstantinopleBlockHeight(int nHeight)
{
    const_cast<CChainParams*>(globalChainParams.get())->UpdateConstantinopleBlockHeight(nHeight);
}

void CChainParams::UpdateDifficultyChangeBlockHeight(int nHeight)
{
    consensus.nSubsidyHalvingInterval = 985500; // fantasygold halving every 4 years
    consensus.posLimit = uint256S("00000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
    consensus.QIP9Height = nHeight;
    consensus.fPowAllowMinDifficultyBlocks = false;
    consensus.fPowNoRetargeting = true;
    consensus.fPoSNoRetargeting = false;
    consensus.nLastPOWBlock = 8800;
    consensus.nMPoSRewardRecipients = 10;
    consensus.nFirstMPoSBlock = consensus.nLastPOWBlock + 
                                consensus.nMPoSRewardRecipients + 
                                COINBASE_MATURITY;
}

void UpdateDifficultyChangeBlockHeight(int nHeight)
{
    const_cast<CChainParams*>(globalChainParams.get())->UpdateDifficultyChangeBlockHeight(nHeight);
}
