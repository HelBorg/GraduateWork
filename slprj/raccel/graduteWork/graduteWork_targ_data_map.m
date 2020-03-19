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
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% rtP.G_0
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.K
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.K_p
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.K_v
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.T_b
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.tau_p1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.tau_p2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.tau_z1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.tau_z2
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.w_fr
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.w_r
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.AWGNChannel1_EbNodB
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.AWGNChannel_EbNodB
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.RandomSource_MeanVal
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.RandomSource_MeanVal_g055kln1nb
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.AWGNChannel1_Ps
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.AWGNChannel_Ps
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtP.AWGNChannel1_seed
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.AWGNChannel_seed
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% rtP.Constant_Value
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant_Value_b4h3lxdqw5
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.TransferFcn1_A
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.TransferFcn1_C
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.Integrator_IC
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.Integrator1_IC
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Integrator2_IC
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.TransferFcn_A
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.TransferFcn_C
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtP.TransferFcn_D
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 11;
	
	  ;% rtP.VariableTimeDelay1_MaxDelay
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 12;
	
	  ;% rtP.VariableTimeDelay1_InitOutput
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 13;
	
	  ;% rtP.PulseGenerator_Amp
	  section.data(13).logicalSrcIdx = 31;
	  section.data(13).dtTransOffset = 14;
	
	  ;% rtP.PulseGenerator_Duty
	  section.data(14).logicalSrcIdx = 32;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtP.PulseGenerator_PhaseDelay
	  section.data(15).logicalSrcIdx = 33;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtP.VariableTimeDelay_MaxDelay
	  section.data(16).logicalSrcIdx = 34;
	  section.data(16).dtTransOffset = 17;
	
	  ;% rtP.VariableTimeDelay_InitOutput
	  section.data(17).logicalSrcIdx = 35;
	  section.data(17).dtTransOffset = 18;
	
	  ;% rtP.PulseGenerator1_Amp
	  section.data(18).logicalSrcIdx = 36;
	  section.data(18).dtTransOffset = 19;
	
	  ;% rtP.PulseGenerator1_Duty
	  section.data(19).logicalSrcIdx = 37;
	  section.data(19).dtTransOffset = 20;
	
	  ;% rtP.PulseGenerator1_PhaseDelay
	  section.data(20).logicalSrcIdx = 38;
	  section.data(20).dtTransOffset = 21;
	
	  ;% rtP.RandomSource_VarianceRTP
	  section.data(21).logicalSrcIdx = 39;
	  section.data(21).dtTransOffset = 22;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates
	  section.data(22).logicalSrcIdx = 40;
	  section.data(22).dtTransOffset = 23;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients
	  section.data(23).logicalSrcIdx = 41;
	  section.data(23).dtTransOffset = 24;
	
	  ;% rtP.PulseGenerator_Amp_dpc1bd5pjc
	  section.data(24).logicalSrcIdx = 42;
	  section.data(24).dtTransOffset = 34;
	
	  ;% rtP.PulseGenerator_Duty_bgi2ymfa2r
	  section.data(25).logicalSrcIdx = 43;
	  section.data(25).dtTransOffset = 35;
	
	  ;% rtP.PulseGenerator_PhaseDelay_atvywtkvwr
	  section.data(26).logicalSrcIdx = 44;
	  section.data(26).dtTransOffset = 36;
	
	  ;% rtP.VariableTimeDelay_MaxDelay_m2225lzqk4
	  section.data(27).logicalSrcIdx = 45;
	  section.data(27).dtTransOffset = 37;
	
	  ;% rtP.VariableTimeDelay_InitOutput_bhowtxsjbn
	  section.data(28).logicalSrcIdx = 46;
	  section.data(28).dtTransOffset = 38;
	
	  ;% rtP.PulseGenerator1_Amp_drqz5ufz4h
	  section.data(29).logicalSrcIdx = 47;
	  section.data(29).dtTransOffset = 39;
	
	  ;% rtP.PulseGenerator1_Duty_g4r4ampfv4
	  section.data(30).logicalSrcIdx = 48;
	  section.data(30).dtTransOffset = 40;
	
	  ;% rtP.PulseGenerator1_PhaseDelay_mbbvjh54k2
	  section.data(31).logicalSrcIdx = 49;
	  section.data(31).dtTransOffset = 41;
	
	  ;% rtP.RandomSource_VarianceRTP_kadmsoaacu
	  section.data(32).logicalSrcIdx = 50;
	  section.data(32).dtTransOffset = 42;
	
	  ;% rtP.VariableTimeDelay_MaxDelay_dusxlj4oib
	  section.data(33).logicalSrcIdx = 51;
	  section.data(33).dtTransOffset = 43;
	
	  ;% rtP.VariableTimeDelay_InitOutput_nbhpmtp2jg
	  section.data(34).logicalSrcIdx = 52;
	  section.data(34).dtTransOffset = 44;
	
	  ;% rtP.DiscreteFIRFilter_InitialStates_bcwzpsb0dc
	  section.data(35).logicalSrcIdx = 53;
	  section.data(35).dtTransOffset = 45;
	
	  ;% rtP.DiscreteFIRFilter_Coefficients_mbm3buv1vn
	  section.data(36).logicalSrcIdx = 54;
	  section.data(36).dtTransOffset = 46;
	
	  ;% rtP.Constant3_Value
	  section.data(37).logicalSrcIdx = 55;
	  section.data(37).dtTransOffset = 56;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtP.Gain_Gain
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Bias_Bias
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Gain1_Gain
	  section.data(3).logicalSrcIdx = 58;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.Gain2_Gain
	  section.data(1).logicalSrcIdx = 59;
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
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% rtB.ljlynbslzt
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.euqkdgostn
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.a4xfolphoz
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.ngd20rywmn
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.cn2zikh4hq
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.oiiuuutb3e
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.gpaqvehfuh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.gpl5i1ekm1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.jc3rovnis0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.nsv3wpjgsy
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.fmn00c1djj
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.ewiw1v51he
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.ehnfvnflet
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.arogusvauw
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.m4x5j3wrne
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.lonj3bmhdp
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtB.gr1lg4b5kc
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtB.ogevcwncpn
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtB.kiwdh5dnyr
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtB.mmtgqryjya
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtB.d2do4by5rh
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtB.dtss3js3fd
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtB.pvii1a3nq2
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtB.f4cfbddfyy
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtB.dq5pf1r1kq
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtB.elxpo0dj2v
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtB.funaqjgfzq
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dwklrf454t
	  section.data(1).logicalSrcIdx = 27;
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
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.akitjtxsla
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hc5gld2nwz
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% rtDW.mcups15blx
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 18;
	
	  ;% rtDW.dpqogci02g
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 19;
	
	  ;% rtDW.mq4qxkalfe
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 20;
	
	  ;% rtDW.jzz1wckozg
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 21;
	
	  ;% rtDW.dgchxx4fdz
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% rtDW.p0fceflrke
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.hxeldrnh31
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jo3vvyegpy
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.fqzlq5lwky
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.kdiskgiof3
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.ezdyi0bpjz.modelTStart
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.bkbzto50nk.modelTStart
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jbx3emlvm2.modelTStart
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.gr2zi5l51e.modelTStart
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtDW.fpgdvluwcr.LoggedData
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.nxvlqwt45o.LoggedData
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 3;
	
	  ;% rtDW.ioqxhb4lhw.AQHandles
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 6;
	
	  ;% rtDW.klz150kukh.AQHandles
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 7;
	
	  ;% rtDW.atsdrurf2g.AQHandles
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 8;
	
	  ;% rtDW.fqydmkxc1f.TUbufferPtrs
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 9;
	
	  ;% rtDW.h20mxqf3h4.TUbufferPtrs
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 11;
	
	  ;% rtDW.pz2yc0tozj.TUbufferPtrs
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 13;
	
	  ;% rtDW.lhx0lj4i05.TUbufferPtrs
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 15;
	
	  ;% rtDW.cg1vpdblix.LoggedData
	  section.data(10).logicalSrcIdx = 25;
	  section.data(10).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.iik5cqzr1o
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.naafmtzk4n
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.o0aqq215bl
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.cdqd414jgr
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.a0nnxzfeub
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.bqbxgzjswl
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.etw2p5ad3w
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.ow1mt1w4wu
	  section.data(8).logicalSrcIdx = 33;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtDW.hlvhcmlowo
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jbppeizd1x
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.bojqotfxnb
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtDW.nc0dkv5gky
	  section.data(4).logicalSrcIdx = 37;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtDW.gn3icq1q2g
	  section.data(5).logicalSrcIdx = 38;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtDW.bizznvvjue
	  section.data(6).logicalSrcIdx = 39;
	  section.data(6).dtTransOffset = 7;
	
	  ;% rtDW.od4sllwisx
	  section.data(7).logicalSrcIdx = 40;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.h4hok5wmjg
	  section.data(8).logicalSrcIdx = 41;
	  section.data(8).dtTransOffset = 634;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.cg25jop35d
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.n3mlm25bwm.Tail
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.idh4wrqtoh.Tail
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.aqjeiun535.Tail
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.mc2bl0bzbl.Tail
	  section.data(4).logicalSrcIdx = 46;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.eihuvcejq2
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lbx1mtfejs
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.j4s4odcqip
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.azmor0scbe
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.myt1d5w44r
	  section.data(5).logicalSrcIdx = 51;
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


  targMap.checksum0 = 1063512293;
  targMap.checksum1 = 359948863;
  targMap.checksum2 = 756139479;
  targMap.checksum3 = 3755340480;

