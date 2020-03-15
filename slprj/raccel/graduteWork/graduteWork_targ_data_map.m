  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtP.K
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.K_p
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.T_b
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.omega_0
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.AWGNChannel1_EbNodB
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.AWGNChannel_EbNodB
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.RandomSource_MeanVal
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.RandomSource_MeanVal_g055kln1nb
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.AWGNChannel1_Ps
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.AWGNChannel_Ps
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtP.AWGNChannel1_seed
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.AWGNChannel_seed
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% rtP.Constant_Value
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant_Value_b4h3lxdqw5
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.TransferFcn1_A
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.TransferFcn1_C
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.TransferFcn_A
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.TransferFcn_C
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtP.TransferFcn_D
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtP.VariableTimeDelay1_MaxDelay
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 9;
	
	  ;% rtP.VariableTimeDelay1_InitOutput
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 10;
	
	  ;% rtP.PulseGenerator_Amp
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 11;
	
	  ;% rtP.PulseGenerator_Duty
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 12;
	
	  ;% rtP.PulseGenerator_PhaseDelay
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtP.VariableTimeDelay_MaxDelay
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtP.VariableTimeDelay_InitOutput
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtP.PulseGenerator1_Amp
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtP.PulseGenerator1_Duty
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 17;
	
	  ;% rtP.PulseGenerator1_PhaseDelay
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 18;
	
	  ;% rtP.RandomSource_VarianceRTP
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 19;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 20;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 21;
	
	  ;% rtP.PulseGenerator_Amp_dpc1bd5pjc
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 31;
	
	  ;% rtP.PulseGenerator_Duty_bgi2ymfa2r
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 32;
	
	  ;% rtP.PulseGenerator_PhaseDelay_atvywtkvwr
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 33;
	
	  ;% rtP.VariableTimeDelay_MaxDelay_m2225lzqk4
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 34;
	
	  ;% rtP.VariableTimeDelay_InitOutput_bhowtxsjbn
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 35;
	
	  ;% rtP.PulseGenerator1_Amp_drqz5ufz4h
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 36;
	
	  ;% rtP.PulseGenerator1_Duty_g4r4ampfv4
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 37;
	
	  ;% rtP.PulseGenerator1_PhaseDelay_mbbvjh54k2
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 38;
	
	  ;% rtP.RandomSource_VarianceRTP_kadmsoaacu
	  section.data(29).logicalSrcIdx = 40;
	  section.data(29).dtTransOffset = 39;
	
	  ;% rtP.VariableTimeDelay_MaxDelay_dusxlj4oib
	  section.data(30).logicalSrcIdx = 41;
	  section.data(30).dtTransOffset = 40;
	
	  ;% rtP.VariableTimeDelay_InitOutput_nbhpmtp2jg
	  section.data(31).logicalSrcIdx = 42;
	  section.data(31).dtTransOffset = 41;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates_bcwzpsb0dc
	  section.data(32).logicalSrcIdx = 43;
	  section.data(32).dtTransOffset = 42;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients_mbm3buv1vn
	  section.data(33).logicalSrcIdx = 44;
	  section.data(33).dtTransOffset = 43;
	
	  ;% rtP.Constant3_Value
	  section.data(34).logicalSrcIdx = 45;
	  section.data(34).dtTransOffset = 53;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtP.Gain_Gain
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Bias_Bias
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Gain1_Gain
	  section.data(3).logicalSrcIdx = 48;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.Gain2_Gain
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% rtB.euqkdgostn
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.a4xfolphoz
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.ngd20rywmn
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.nsv3wpjgsy
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.nn4m2ue31i
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.fmn00c1djj
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.arogusvauw
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.m4x5j3wrne
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.lonj3bmhdp
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.gr1lg4b5kc
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.ogevcwncpn
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.kiwdh5dnyr
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.mmtgqryjya
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.d2do4by5rh
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.dtss3js3fd
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.pvii1a3nq2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtB.f4cfbddfyy
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtB.dq5pf1r1kq
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtB.elxpo0dj2v
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtB.hz5dwxxhh5
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dwklrf454t
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtDW.akitjtxsla
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hc5gld2nwz
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% rtDW.gidxstxvag
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% rtDW.ewu2ifjblb
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% rtDW.hrgwoqkxsi
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% rtDW.hqrrzfrnm4
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% rtDW.mcups15blx
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% rtDW.dpqogci02g
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% rtDW.mq4qxkalfe
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 24;
	
	  ;% rtDW.jzz1wckozg
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 25;
	
	  ;% rtDW.dgchxx4fdz
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 26;
	
	  ;% rtDW.p0fceflrke
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.hxeldrnh31
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jo3vvyegpy
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.fqzlq5lwky
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kdiskgiof3
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.ezdyi0bpjz.modelTStart
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bkbzto50nk.modelTStart
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jbx3emlvm2.modelTStart
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.gr2zi5l51e.modelTStart
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.hewqvudxrp.LoggedData
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bglwdv4oyw.LoggedData
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.k3nx12mzik.LoggedData
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.fqydmkxc1f.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.h20mxqf3h4.TUbufferPtrs
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtDW.pz2yc0tozj.TUbufferPtrs
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtDW.lhx0lj4i05.TUbufferPtrs
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.cg1vpdblix.LoggedData
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.iik5cqzr1o
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.naafmtzk4n
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.o0aqq215bl
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.cdqd414jgr
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.a0nnxzfeub
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.bqbxgzjswl
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.etw2p5ad3w
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.ow1mt1w4wu
	  section.data(8).logicalSrcIdx = 35;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.hlvhcmlowo
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jbppeizd1x
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.bojqotfxnb
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtDW.nc0dkv5gky
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtDW.gn3icq1q2g
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtDW.bizznvvjue
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtDW.od4sllwisx
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.h4hok5wmjg
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 634;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cg25jop35d
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.n3mlm25bwm.Tail
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.idh4wrqtoh.Tail
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.aqjeiun535.Tail
	  section.data(3).logicalSrcIdx = 47;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.mc2bl0bzbl.Tail
	  section.data(4).logicalSrcIdx = 48;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.eihuvcejq2
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lbx1mtfejs
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.j4s4odcqip
	  section.data(3).logicalSrcIdx = 51;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.azmor0scbe
	  section.data(4).logicalSrcIdx = 52;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.myt1d5w44r
	  section.data(5).logicalSrcIdx = 53;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4170770201;
  targMap.checksum1 = 232831895;
  targMap.checksum2 = 2260892825;
  targMap.checksum3 = 3417646548;

