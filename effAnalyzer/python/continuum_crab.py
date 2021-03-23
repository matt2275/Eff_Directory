from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferLogs = False
config.General.transferOutputs = True
config.General.workArea = 'HI_Forward_Continuum'
config.General.requestName = 'HLT_Efficiency'
config.section_('JobType')
config.JobType.psetName = '/afs/cern.ch/user/m/mnickel/private/EFF_ANALYZER/CMSSW_10_3_3_patch1/src/Eff_Directory/effAnalyzer/python/eff_muon_data.py'
config.JobType.pluginName = 'Analysis'
config.JobType.allowUndistributedCMSSW = True
config.section_('Data')
config.Data.inputDataset = '/HIForward/HIRun2018A-04Apr2019-v1/AOD'
#config.Data.inputDataset = '/JPsi_pThat-2_TuneCP5_HydjetDrumMB_5p02TeV_Pythia8/HINPbPbAutumn18DR-mva98_103X_upgrade2018_realistic_HI_v11-v1/AODSIM'
config.Data.ignoreLocality = False
config.Data.unitsPerJob     = 200#5000
config.Data.totalUnits      = 700000
config.Data.splitting       ='EventAwareLumiBased'#'LumiBased'#'FileBased'#EventAwareLumiBased'Automatic
#config.JobType.maxMemoryMB = 2500
config.Data.lumiMask = 'Cert_326381-327564_HI_PromptReco_Collisions18_JSON_HF_and_MuonPhys.txt'
config.Data.outLFNDirBase = '/store/user/mnickel/TauTau/Crab'  #outfile Location
config.Data.publication = False
config.section_('Site')
config.Site.storageSite = 'T3_CH_CERNBOX'  #needed to save to cernbox 
