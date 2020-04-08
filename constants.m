pi = 3.14;


% For FM mode

Ac = 1; % Amplitude frequency
fc = 36; % center frequency
kf = 7.8; % gain of the modulator -> so that RF bandwidth of the FM-DCSK siganl is 17 when the chip rate is 20

Tau = 100; %time of generation


T_b = 2; % period for dcsk
T = T_b;
apll_const();

K = 3;

R = 9;





