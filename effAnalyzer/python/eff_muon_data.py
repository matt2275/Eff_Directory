import FWCore.ParameterSet.Config as mumu

process = mumu.Process('HLTTRACKING')
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
process.MessageLogger.categories.append('HLTrigReport')
process.MessageLogger.categories.append('L1GtTrigReport')
process.options = mumu.untracked.PSet( wantSummary = mumu.untracked.bool(True) )
process.load("CondCore.CondDB.CondDB_cfi")

process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load("Configuration.StandardSequences.GeometryRecoDB_cff")

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.MessageLogger.cerr.FwkReport.reportEvery = 5000
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
#process.GlobalTag.globaltag = "103X_dataRun2_v6"
process.GlobalTag.globaltag = "103X_upgrade2018_realistic_HI_v13"
process.maxEvents = mumu.untracked.PSet(
    input = mumu.untracked.int32(-1)
)
#Filters for open trigger
#L1: L1_SingleMuOpen_NotMinimumBiasHF2_AND_BptxAND
#HLT: hltL1sSingleMuOpenNotMBHF2AND

#Filters for not open trigger
#L1 filter: hltL1sSingleMu0NotMBHF2AND
#HLT filter: hltPreHIUPCSingleMu0NotMBHF2AND


file_HIAOD = mumu.untracked.vstring(
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_99.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_98.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_97.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_96.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_95.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_94.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_93.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_92.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_91.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_90.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_9.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_89.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_88.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_87.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_86.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_85.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_84.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_83.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_82.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_81.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_80.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_8.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_79.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_78.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_77.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_76.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/510000/CF6A3291-A105-4047-A2FF-6607AB5DB522.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/510000/A241B73E-FF58-2045-AD18-25CF19CCDE42.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/510000/91466CAA-F1A1-B141-BC3E-DE4C33AC7AE7.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/510000/64322A57-5284-4D4D-BF54-697D1B7C58A4.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/510000/1EF91FDD-17C2-394D-9FE0-4F7E08CB01EF.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/510000/1080EE79-547B-0E4C-B2D1-01892D74D03E.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/510000/01493810-256D-9B4E-B2BF-39C10D9B91A6.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/50006/FF372A38-2521-ED46-8587-168B1A2CC0F6.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/50006/FEC0FE72-3D90-554A-BFD5-B1861855B9DA.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/50006/FE2CE0B4-3349-E24A-BE9E-C77A22FA0EF8.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/50006/FD757ED1-6018-9141-AF64-877FF5C69DFA.root',
#'root://cms-xrd-global.cern.ch//store/hidata/HIRun2018A/HIForward/AOD/04Apr2019-v1/50006/FD1B33CC-30F4-7A4F-B030-3691FBD0284F.root',
  )



inputFiles = file_HIAOD
outputFile = "/eos/user/m/mnickel/TauTau/continuum_sample_check_deltaR.root"
print("AOD input files are used")
process.source = mumu.Source ("PoolSource", fileNames = inputFiles )



process.eff = mumu.EDAnalyzer('effAnalyzer',
         isMCstudy                 = mumu.bool(False),
         JpsiWindow                = mumu.double(0.31),
         genEventInfoProduct       = mumu.untracked.InputTag('generator'),
         muon                      = mumu.untracked.InputTag("muons"),
         primaryvertex             = mumu.untracked.InputTag("offlinePrimaryVertices"),
         track                     = mumu.untracked.InputTag("generalTracks"),
         geninfo                   = mumu.untracked.InputTag("genParticles"),
         triggerresults            = mumu.untracked.InputTag("TriggerResults","","HLT"),
         samuontrack               = mumu.untracked.InputTag("standAloneMuons"),
         trigsummary               = mumu.untracked.InputTag("hltTriggerSummaryAOD","", "HLT"),
         filtertag                 = mumu.untracked.InputTag("hltL1sSingleMuOpenNotMBHF2AND", "", "HLT"),
         pathsToSave               = mumu.vstring("HLT_HIUPC_SingleMu0_NotMBHF2AND_v1","HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1",),#HLT_HIUPC_SingleMu0_NotMBHF2AND_v1,HLT_HIUPC_SingleMuOpen_NotMBHF2AND_v1
         filterToMatch             = mumu.vstring("hltL1sSingleMu0NotMBHF2AND","hltL1sSingleMuOpenNotMBHF2AND",),
         offlineBS                 = mumu.untracked.InputTag("offlineBeamSpot"),#"","RECO"),
         l1MuonTag                 = mumu.untracked.InputTag("gmtStage2Digis","Muon","RECO"),
         CentralitySrc             = mumu.untracked.InputTag("hiCentrality"),
         CentralityBinSrc          = mumu.untracked.InputTag("centralityBin","HFtowers"),
         HLTprocess                = mumu.string("HLT"),
         doMuon                    = mumu.bool(True),

)

#Filters for open trigger
#L1: L1_SingleMuOpen_NotMinimumBiasHF2_AND_BptxAND
#HLT: hltL1sSingleMuOpenNotMBHF2AND

#Filters for not open trigger
#L1 filter: hltL1sSingleMu0NotMBHF2AND
#HLT filter: hltPreHIUPCSingleMu0NotMBHF2AND


process.GlobalTag.snapshotTime = mumu.string("9999-12-31 23:59:59.000")
process.GlobalTag.toGet.extend([
    mumu.PSet(record = mumu.string("HeavyIonRcd"),
        tag = mumu.string("CentralityTable_HFtowers200_DataPbPb_periHYDJETshape_run2v1033p1x01_offline"),
        connect = mumu.string("frontier://FrontierProd/CMS_CONDITIONS"),
        label = mumu.untracked.string("HFtowers")
        ),
    ])

process.load("RecoHI.HiCentralityAlgos.CentralityBin_cfi")
process.centralityBin.Centrality = mumu.InputTag("hiCentrality")
process.centralityBin.centralityVariable = mumu.string("HFtowers")
#process.centralityBin
#process.p = mumu.Path(
    #process.zerobiasfilter*
   # process.LumiInfo*
   # process.LumiHFInfo*
 #   process.centralityBin * 
   # process.lumi
#    )


process.TFileService = mumu.Service("TFileService",
                                   fileName = mumu.string( outputFile )
                                   )

process.p = mumu.Path(process.centralityBin*process.eff)
