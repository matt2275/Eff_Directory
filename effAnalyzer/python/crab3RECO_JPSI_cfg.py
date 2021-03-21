from WMCore.Configuration import Configuration
config = Configuration()

config.section_('General')
config.General.requestName = 'TrkTrig_Efficiency'
#request name is the name of the folder where crab log is saved
config.General.workArea = 'HI_DATA_Continum'
config.General.transferOutputs = True
config.General.transferLogs = False

config.section_('JobType')
config.JobType.psetName = '/afs/cern.ch/work/m/mumuhamm/private/CMSSW_10_3_3_patch1/src/Eff_Directory/effAnalyzer/python/eff_muon_data.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['trktrig_eff_UPCSMuon_Continuum_Data.root']
config.JobType.allowUndistributedCMSSW = True

config.section_('Data')

config.Data.lumiMask = 'Cert_326381-327564_HI_PromptReco_Collisions18_JSON_HF_and_MuonPhys.txt'
config.Data.inputDataset = '/HIForward/HIRun2018A-04Apr2019-v1/AOD'
#config.Data.inputDataset = '/JPsiMM_5p02TeV_TuneCP5_Embd/anstahll-JPsiMM_5p02TeV_TuneCP5_Embd_RECO_20190326-5db5dfa073297cb96791f14c622e83e2/USER'
config.Data.unitsPerJob     = 2500#5000
config.Data.totalUnits      = 7000000
config.Data.splitting       = 'LumiBased'#'Automatic'#EventAwareLumiBased'
config.JobType.maxMemoryMB = 5000
config.Data.outLFNDirBase = '/store/user/mumuhamm/HIEFF_Data'
config.Data.publication = False
config.Data.ignoreLocality = False
config.section_("Site")
#config.Site.storageSite = 'T2_IN_TIFR'
config.Site.storageSite = 'T2_CH_CERNBOX'#T3_US_FNALLPC'










