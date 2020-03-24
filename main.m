clear

global pi Ac fc kf;
% Constants


pi = 3.14;


% For FM mode

Ac = 1; % Amplitude frequency
fc = 36; % center frequency
kf = 7.8; % gain of the modulator -> so that RF bandwidth of the FM-DCSK siganl is 17 when the chip rate is 20

Tau = 100; %time of generation
T = 2; % bit duration
T_b = 40; %random for now; period for dcsk

omega_0 = 700;
w_r = 700;
w_fr = 0;

A_u0 = db2mag(1);
K_v = db2mag(1);
K_p = db2mag(1);
g = 90.8/K_v/K_p;
G_0 = db2mag(g)

tau_p1 = 1.65*1e-3;
tau_p2 = 1.65*1e-3;
tau_z1 = 165*1e-6;
tau_z2 = 165*1e-6;

K = 3;

R = 9;

Tb = T/2;



