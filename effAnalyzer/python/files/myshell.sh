#!/bin/sh

#for ((i=1;i<=100;i++));
#path = xrdcp -r root://se01.indiacms.res.in:1094//cms/store/user/mumuhamm/HIEFF_Data/HIForward/crab_TrkTrig_Efficiency/200827_181525/0000/trktrig_eff_UPCSMuon_Continuum_Data_ 
for var in {0..100}
do
   echo "xrdcp -r root://se01.indiacms.res.in:1094//cms/store/user/mumuhamm/HIEFF_Data/HIForward/crab_TrkTrig_Efficiency/200827_181525/0000/trktrig_eff_UPCSMuon_Continuum_Data_$var.root ."
done
