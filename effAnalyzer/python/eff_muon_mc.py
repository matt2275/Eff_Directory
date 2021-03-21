import FWCore.ParameterSet.Config as mumu

process = mumu.Process('HLTTRACKING')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
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


process.source = mumu.Source("PoolSource",
    fileNames = mumu.untracked.vstring(
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
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_75.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_74.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_73.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_72.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_71.root',
'root://xrootd.unl.edu//store/user/shuaiy/RiceHIN/STARlight/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/GammaGamma2MuMu_GENSIM_woPtCut_PbPb5TeV_v1/STARlight_GammaGamma2MuMu_Reco_woPtCut_PbPb5TeV_v1/191111_221615/0000/step3_RECO_70.root',
  )
)

process.eff = mumu.EDAnalyzer('effAnalyzer',
         isMCstudy                 = mumu.bool(True),
         JpsiWindow                = mumu.double(0.31),
         muon                      = mumu.untracked.InputTag("muons"),
         primaryvertex             = mumu.untracked.InputTag("offlinePrimaryVertices"),
         track                     = mumu.untracked.InputTag("generalTracks"),
         geninfo                   = mumu.untracked.InputTag("genParticles","","SIM"),
         triggerresults            = mumu.untracked.InputTag("TriggerResults","","HLT"),
         samuontrack               = mumu.untracked.InputTag("standAloneMuons"),
         trigsummary               = mumu.untracked.InputTag("hltTriggerSummaryAOD","", "HLT"),
         filtertag                 = mumu.untracked.InputTag("hltL1sSingleMuOpenNotMBHF2AND","","HLT"),#(hltL1sSingleMu0NotMBHF2AND", "", "HLT"),
         offlineBS                 = mumu.untracked.InputTag("offlineBeamSpot","","RECO"),
)



process.TFileService = mumu.Service("TFileService",
                                    fileName = mumu.string('trktrig_eff_UPCSMuon_Continuum_MC.root')
)


process.p = mumu.Path(process.eff)
