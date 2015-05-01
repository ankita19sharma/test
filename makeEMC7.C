
//macro to make a .root file which contains an AliRDHFCutsDplustoKpipi with loose set of cuts (for significance maximization) and TParameter with the tighest value of these cuts
//Needed for AliAnalysisTaskSEDplus, AliCFTaskVertexingHF3Prong, AliAnalysisTaskSESignificance

//Use:
//Set hard coded commented with //set this!!

//.L makeTFile4CutsDplustoKpipi.C
// makeInputAliAnalysisTaskSEDplus()
// makeInputAliAnalysisTaskSESignificanceMaximization()

//similar macros for the other D mesons

//Author: Chiara Bianchin, cbianchi@pd.infn.it
//        Giacomo Ortona, ortona@to.infn.it
//        Renu Bala [Dplus Analysis and CF]

void makeInputAliAnalysisTaskSEDplus(){

  gSystem->SetIncludePath("-I. -I$ROOTSYS/include -I$ALICE_PHYSICS -I$ALICE_PHYSICS/../src/include -I$ALICE_PHYSICS/../src/ITS -I$ALICE_PHYSICS/../src/TPC -I$ALICE_PHYSICS/../src/CONTAINERS -I$ALICE_PHYSICS/../src/STEER/STEER -I$ALICE_PHYSICS/../src/STEER/STEERBase -I$ALICE_PHYSICS/../src/STEER/ESD -I$ALICE_PHYSICS/../src/STEER/AOD -I$ALICE_PHYSICS/../src/TRD -I$ALICE_PHYSICS/../src/macros -I$ALICE_PHYSICS/../src/ANALYSIS  -I$ALICE_PHYSICS/../src/OADB -I$ALICE_PHYSICS/../src/PWGHF -I$ALICE_PHYSICS/../src/PWGHF/base -I$ALICE_PHYSICS/../src/PWGHF/vertexingHF -I$ALICE_PHYSICS/../src/PWG/FLOW/Base -I$ALICE_PHYSICS/../src/PWG/FLOW/Tasks -g"); 
 

    AliESDtrackCuts* esdTrackCuts=new AliESDtrackCuts();
    esdTrackCuts->SetRequireSigmaToVertex(kFALSE);
    //default
    esdTrackCuts->SetRequireTPCRefit(kTRUE);
    esdTrackCuts->SetRequireITSRefit(kTRUE);
    //esdTrackCuts->SetMinNClustersITS(4); // default is 5
    esdTrackCuts->SetMinNClustersTPC(70);
    esdTrackCuts->SetClusterRequirementITS(AliESDtrackCuts::kSPD,
					   AliESDtrackCuts::kAny); 
    // default is kBoth, otherwise kAny
    esdTrackCuts->SetMinDCAToVertexXY(0.);
    esdTrackCuts->SetPtRange(0.3,1.e10);
    
    
    
    const Int_t nptbins=18;
    Float_t* ptbins;
    ptbins=new Float_t[nptbins+1];
   
   ptbins[0]=0.;
   ptbins[1]=1;	
   ptbins[2]=2.;
   ptbins[3]=3.;
   ptbins[4]=4.;
   ptbins[5]=5.;
   ptbins[6]=6.;
   ptbins[7]=7.;
   ptbins[8]=8.;
   ptbins[9]=9.;
   ptbins[10]=10.;
   ptbins[11]=12.;
   ptbins[12]=14.;
   ptbins[13]=16.;
   ptbins[14]=24.;
   ptbins[15]=36.;
   ptbins[16]=40.;    
   ptbins[17]=48.;  
   ptbins[18]=52.;   
    const Int_t nvars=14;
    

    Float_t** anacutsval;
    anacutsval=new Float_t*[nvars];
    
    for(Int_t ic=0;ic<nvars;ic++){anacutsval[ic]=new Float_t[nptbins];}
    //Double_t cutsDplus[12]={0.2,0.4,0.4,0.,0.,0.01,0.06,0.02,0.,0.85,0.,10000000000.};
   
     for(Int_t ipt=0;ipt<nptbins;ipt++){
    anacutsval[0][ipt]=0.2;
    anacutsval[3][ipt]=0.;
    anacutsval[4][ipt]=0.;
    anacutsval[5][ipt]=0.01;
    anacutsval[11][ipt]=10000000000.;
    }

  anacutsval[1][0]=0.3;
  anacutsval[1][1]=0.4;
  anacutsval[1][2]=0.4; 
  anacutsval[1][14]=0.4; 

  anacutsval[2][0]=0.3;
  anacutsval[2][1]=0.3;
  anacutsval[2][2]=0.4; 
  anacutsval[2][14]=0.3;  
  for(Int_t ipt=3;ipt<nptbins;ipt++){
    anacutsval[1][ipt]=0.4;
    anacutsval[2][ipt]=0.4;
  }
  
  anacutsval[6][0]=0.022100;
  anacutsval[6][1]=0.022100;
  anacutsval[6][2]=0.034;
  anacutsval[6][3]=0.020667;
  anacutsval[6][4]=0.020667;
  anacutsval[6][5]=0.023333;
  anacutsval[6][14]=0.049999;


  // anacutsval[6][14]=0.051111;
    
  
  anacutsval[7][0]=0.08;
  anacutsval[7][1]=0.08;
  anacutsval[7][2]=0.09;  
  anacutsval[7][3]=0.095;
  anacutsval[7][4]=0.095;
 
  anacutsval[7][14]=0.08;

   
  anacutsval[8][0]=0.5;
  anacutsval[8][1]=0.5;
  anacutsval[8][2]=1.0;
  anacutsval[8][3]=0.5;
  anacutsval[8][4]=0.5;
  anacutsval[8][14]=0.;    
    
  anacutsval[9][0]=0.97;
  anacutsval[9][1]=0.936;
  anacutsval[9][2]=0.95; 
  anacutsval[9][3]=0.95; 
  anacutsval[9][4]= 0.95;
  anacutsval[9][5]=0.92;
  anacutsval[9][6]=0.92;
  anacutsval[9][7]=0.92;
  anacutsval[9][8]=0.92;
  anacutsval[9][9]=0.90;
  
  anacutsval[9][14]=0.81;

 for(Int_t ipt=10;ipt<nptbins;ipt++){
   anacutsval[9][ipt]=0.90; 
 }
  
  
  anacutsval[10][0]=0.0055;
  anacutsval[10][1]=0.0055;
  anacutsval[10][2]= 0.0028;
  anacutsval[10][3]=0.000883;
  anacutsval[10][4]=0.000883;
  anacutsval[10][14]=0.0008833;

  
  for(Int_t ipt=5;ipt<nptbins;ipt++){
    anacutsval[6][ipt]=0.02333;
    anacutsval[7][ipt]=0.115;
    anacutsval[8][ipt]=0.5;
    anacutsval[10][ipt]=0.000883;
    }   

  anacutsval[12][0]=8;
  anacutsval[12][1]=8;
  
  anacutsval[13][0]=0.98;
  anacutsval[13][1]=0.98;
  anacutsval[13][1]=-1.0; 
  for(Int_t ipt=2;ipt<nptbins;ipt++){
    anacutsval[12][ipt]=0.;
    anacutsval[13][ipt]=0.;
 }
  
  
    
            
 

    
    
    AliRDHFCutsDplustoKpipi* analysiscuts=new AliRDHFCutsDplustoKpipi();
    analysiscuts->SetName("AnalysisCuts");
    analysiscuts->SetTitle("Cuts for Dplus Analysis and CF");
    analysiscuts->SetPtBins(nptbins+1,ptbins);
    analysiscuts->SetCuts(nvars,nptbins,anacutsval);
    analysiscuts->AddTrackCuts(esdTrackCuts);
    analysiscuts->SetUsePID(kTRUE);

    //analysiscuts->ApplySPDMisalignedCutPP2012();

    cut->ApplySPDMisalignedCutPP2012();
    analysiscuts->SetUseStrongPid(3);
    analysiscuts->SetMaxPtStrongPid(8.);
    analysiscuts->SetMaxPStrongPidK(1.5);
    analysiscuts->SetMaxPStrongPidpi(1.5); 

    //analysiscuts->SetUseEMCAL7TriggerPP2012(); 

    analysiscuts->SetRemoveDaughtersFromPrim(kFALSE);
    analysiscuts->SetOptPileup(kTRUE);
    analysiscuts->SetUseImpParProdCorrCut(kFALSE);
    //  analysiscuts->SetMinPtCandidate(5.);
    //analysiscuts->SetMaxPtCandidate(10000.);
    // analysiscuts->SetMaxVtxZ(10.);
    cout<<"This is the odject I'm going to save:"<<nptbins<<endl;
    
    analysiscuts->PrintAll();
    TFile* fout=new TFile("DplustoKpipiSC_EMC7.root","recreate");   
    fout->cd();
    analysiscuts->Write();
    fout->Close();
    
    
}


void makeInputAliAnalysisTaskSESignificanceMaximization(){
  
  AliRDHFCutsDplustoKpipi* RDHFDplustoKpipi=new AliRDHFCutsDplustoKpipi();
  RDHFDplustoKpipi->SetName("loosercuts");
  RDHFDplustoKpipi->SetTitle("Cuts for significance maximization");

  AliESDtrackCuts* esdTrackCuts=new AliESDtrackCuts();
  esdTrackCuts->SetRequireSigmaToVertex(kFALSE);
  //default
  esdTrackCuts->SetRequireTPCRefit(kTRUE);
  esdTrackCuts->SetRequireITSRefit(kTRUE);
  //esdTrackCuts->SetMinNClustersITS(4); // default is 5
  esdTrackCuts->SetMinNClustersTPC(70);
  esdTrackCuts->SetClusterRequirementITS(AliESDtrackCuts::kSPD,
					 AliESDtrackCuts::kAny); 
  // default is kBoth, otherwise kAny
  esdTrackCuts->SetMinDCAToVertexXY(0.);
  esdTrackCuts->SetPtRange(0.3,1.e10);

  RDHFDplustoKpipi->AddTrackCuts(esdTrackCuts);

  const Int_t nvars=12;

  const Int_t nptbins=4;
  Float_t* ptbins;
  ptbins=new Float_t[nptbins+1];
  ptbins[0]=0.;
  ptbins[1]=2.;
  ptbins[2]=3.;
  ptbins[3]=5.;
  ptbins[4]=99999.;
  
  RDHFDplustoKpipi->SetPtBins(nptbins+1,ptbins);
    
  //setting my cut values
    
  Float_t** prodcutsval;
  prodcutsval=new Float_t*[nvars];
  for(Int_t ic=0;ic<nvars;ic++){prodcutsval[ic]=new Float_t[nptbins];}  
  for(Int_t ipt=0;ipt<nptbins;ipt++){
    prodcutsval[0][ipt]=0.2;
    prodcutsval[1][ipt]=0.4;
    prodcutsval[2][ipt]=0.4;
    prodcutsval[3][ipt]=0.;
    prodcutsval[4][ipt]=0.;
    prodcutsval[5][ipt]=0.01;
    prodcutsval[6][ipt]=0.06;
    prodcutsval[7][ipt]=0.02;
    prodcutsval[8][ipt]=0.;
    prodcutsval[9][ipt]=0.85;
    prodcutsval[10][ipt]=0.;
    prodcutsval[11][ipt]=10000000.0;
    
  }

  RDHFDplustoKpipi->SetCuts(nvars,nptbins,prodcutsval);

  Int_t nvarsforopt=RDHFDplustoKpipi->GetNVarsForOpt();
  const Int_t dim=5; //set this!!
  Bool_t *boolforopt;
  boolforopt=new Bool_t[nvars];
  if(dim>nvarsforopt){
    cout<<"Number of variables for optimization has probably changed, check and edit accordingly"<<endl;
    return;
  } else {
    if(dim==nvarsforopt){
      boolforopt=RDHFDplustoKpipi->GetVarsForOpt();
    }else{
      TString *names;
      names=new TString[nvars];
      TString answer="";
      Int_t checktrue=0;
      names=RDHFDplustoKpipi->GetVarNames();
      for(Int_t i=0;i<nvars;i++){
	cout<<names[i]<<" for opt? (y/n)"<<endl;
	cin>>answer;
	if(answer=="y") {
	  boolforopt[i]=kTRUE;
	  checktrue++;
	}
	else boolforopt[i]=kFALSE;
      }
      if (checktrue!=dim) {
	cout<<"Error! You set "<<checktrue<<" kTRUE instead of "<<dim<<endl;
	return;
      }
      RDHFDplustoKpipi->SetVarsForOpt(dim,boolforopt);
    }
  }


  Float_t tighterval[dim][nptbins];
  //sigmavert
  //declength
  //Pmax
  //costhetapoint
  //sumd02

  //number of steps for each variable is 4 now
  //set this!!

  // tighterval[var][ptbin]
  tighterval[0][0]=0.022100;
  tighterval[0][1]=0.034;
  tighterval[0][2]=0.020667;
  tighterval[0][3]=0.023333;

  tighterval[1][0]=0.08;
  tighterval[1][1]=0.09;
  tighterval[1][2]=0.095;
  tighterval[1][3]=0.115;

  tighterval[2][0]=1.;
  tighterval[2][1]=1.;
  tighterval[2][2]=1.;
  tighterval[2][3]=1.;
  
  tighterval[3][0]=0.979;
  tighterval[3][1]=0.9975;
  tighterval[3][2]=0.995;
  tighterval[3][3]=0.9975;
  
  tighterval[4][0]=0.0055;
  tighterval[4][1]=0.0028;
  tighterval[4][2]=0.000883;
  tighterval[4][3]=0.000883;

  TString name=""; 
  Int_t arrdim=dim*nptbins;
  TClonesArray max("TParameter<float>",arrdim);
  for (Int_t ipt=0;ipt<nptbins;ipt++){
    for(Int_t ival=0;ival<dim;ival++){
      name=Form("par%dptbin%d",ival,ipt);
      new(max[ipt*dim+ival])TParameter<float>(name.Data(),tighterval[ival][ipt]);
    }
  }

  TFile* fout=new TFile("cuts4SignifMaximDplus.root","recreate");   //set this!! 
  fout->cd();
  RDHFDplustoKpipi->Write();
  max.Write();
  fout->Close();

}
