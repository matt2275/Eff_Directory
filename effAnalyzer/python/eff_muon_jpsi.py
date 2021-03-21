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
    input = mumu.untracked.int32(100000)
)


process.source = mumu.Source("PoolSource",
    fileNames = mumu.untracked.vstring(
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/60000/FD1FE6A7-C77C-964E-B94E-7CBCEA7CB0CE.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/60000/FB364269-D9CD-1948-9235-EDF011782FC7.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/60000/FAA7394A-E83C-CD47-BCFE-4BCC774A8FD0.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/60000/DD904409-B7AC-DB40-AA37-821D8C4C81F2.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/60000/6A43617D-246F-BA44-B21C-ADDDC0514BDE.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/60000/3FBD850B-9E10-454E-93FD-A0935FE1692C.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/F9209A0E-EA56-354F-8A07-0403A6316DA4.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/F2B72AFF-69C7-3C4B-861D-E244B4FE89A2.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/BA3C2251-C43B-944C-B47D-EE8BAD2389B8.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/9CEFAD7D-ED8A-2947-8C3D-0F2D1574A21F.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/734EBF1C-40D7-014C-9A09-DF5CFCDD2124.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/68EFE09B-A460-4747-ADE9-C5182ABF4DC5.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/66EE5A91-E232-2D44-80A7-6A0C78333432.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/37DE8F5C-DA0F-A64A-92D6-D0D9A8C3CFFF.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/2175077C-5C4D-B048-82EC-D2016425D8C8.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40002/17190580-9CB0-574E-BAAF-E760802E6026.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FF9308F6-6B6E-3746-99B9-3D8CA7BDF3F5.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FF813C82-264E-FC4C-B091-59C50A054E0A.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FF756098-30D5-6345-B760-AD26404E67AE.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FF73138A-31DA-734F-AB0F-5C51A3722634.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FF1EBE5F-5BAA-1C4B-8D47-FA6E91678A42.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FF17EE98-C850-9147-BA52-F74BE47A20B1.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FEC49556-D7A7-AD42-B86E-B6B01BE20589.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FEC105C4-B389-C341-954A-25286CE31D5C.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FE878E97-AC63-1E49-819E-8BBC3A3D71B6.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FE3C1F61-E216-6949-88BF-6132D74D7869.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FD592F86-0B93-5D40-A056-B2864A4EF98E.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FC7B0AFB-B4A5-984B-B87A-AE0858786F32.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FC2C2ADB-05C4-844D-8934-010831FE3433.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FC0BA677-1A0F-264A-AD59-C85FB6080F05.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FBBAEA55-094D-054E-B35A-40FEDBA0F6DB.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FB8034B8-F46A-344D-848D-87F87446C773.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FB54C29E-A23A-A74B-B38F-35B088264079.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FB5081EC-F1A4-584D-8D07-0B643FC90858.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FB399C00-502B-CC42-A7BF-AE5D5F00CFB0.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FB2B91E7-D452-8945-905C-336096FF2128.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/FA9413AB-558E-F74C-A7DF-07B88AD69B27.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F9D85EC5-7B6A-7846-A17A-5C3F9588DBBC.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F9B8671B-7E37-B54C-BA72-D40D39757ACA.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F9ACE6B5-2C00-6249-92A3-14BA66B6085D.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F92F876B-9B78-564A-9E12-A2941BFBBD90.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F90AAD43-84D8-5C42-BE87-422F6D772B05.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F90A469D-2BFF-A74F-9144-AB34E2714A38.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F8C92163-FF59-4644-8BE5-2F6D5E7AA4A1.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F8BE9DDC-65A5-244A-AD89-F8FA4F1F14BA.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F8970CE4-0C2A-DC4F-AA51-EA13DA98AFD5.root',
 'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F8823A18-420E-7D49-87C4-933392E7281F.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F87EEAC3-7D9D-584E-874B-13EF1B65EDA2.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F87B4130-F595-4848-B75A-D2B840FDDF94.root',
'root://cms-xrd-global.cern.ch//store/himc/HINPbPbAutumn18DR/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/AODSIM/mva98_103X_upgrade2018_realistic_HI_v11-v1/40001/F834595B-E929-F34A-BCE5-C8DF3F5AFFF7.root',
)
)

process.eff = mumu.EDAnalyzer('effAnalyzer',
         isMCstudy                 = mumu.bool(False),
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
                                    fileName = mumu.string('trktrig_eff_UPCSMuon_Open_InclusiveJpsi.root')
)


process.p = mumu.Path(process.eff)
