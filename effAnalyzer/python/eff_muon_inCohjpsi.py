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



file_HIAOD = mumu.untracked.vstring(
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_20.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_21.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_22.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_23.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_24.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_25.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_26.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_27.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_28.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_29.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_30.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_31.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_32.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_33.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_34.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_35.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_36.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_37.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_38.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_39.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_40.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_41.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_42.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_43.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_44.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_45.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_46.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_47.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_48.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_49.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_50.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_51.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_52.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_53.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_54.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_55.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_56.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_57.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_58.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_59.root',
'root://cms-xrd-global.cern.ch//store/user/shuaiy/RiceHIN/STARlight/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/STARlight_InCohJpsi2MuMu_PbPb5TeV/STARlight_InCohJpsi2MuMu_PbPb5TeV_Reco_v1/200223_231838/0000/step3_InCohJpsi_Reco_60.root',
)

inputFiles = file_HIAOD
outputFile = "Inclusive_Jpsi.root"
print("AOD input files are used")
process.source = mumu.Source ("PoolSource", fileNames = inputFiles ) 


process.eff = mumu.EDAnalyzer('effAnalyzer',
         isMCstudy                 = mumu.bool(True),
         JpsiWindow                = mumu.double(0.31),
         genEventInfoProduct       = mumu.untracked.InputTag('generator'),
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
                                    fileName = mumu.string('trktrig_eff_UPCSMuon_Open_inCohJpsi.root')
)


process.p = mumu.Path(process.eff)
