clc
clear

global pi Ac fc kf;
% Constants

tau_p1 = 1.65;
tau_p2 = 1.65;
tau_z1 = 165;
tau_z2 = 165;
pi = 3.14;


% For FM mode

Ac = 1; % Amplitude frequency
fc = 36; % center frequency
kf = 7.8; % gain of the modulator -> so that RF bandwidth of the FM-DCSK siganl is 17 when the chip rate is 20

Tau = 100; %time of generation
T = 2; % bit duration
T_b = 40; %random for now; period for dcsk

% G_0   K_v    K_p    A_u0    omega_0  w_r  w_fr
% 90.8  2      2      22.7    0        5    5
% 90.8  2      2      22.7    0        700  700
% 90.8  2      2      22.7    0        1400 1400 
% 90.8  2      2      22.7    0        1e+10 1e+10
% 97.3  3      3      10.811
% 94    2      4      11.75   1400     2000 600
% % 90.8  2      2      22.7    700      1400 700 
% 90.8  2      2      22.7    700      900  200

omega_0 = 0;
G_0 = db2mag(90.8);
% K_v = 3;    
% K_p = 3;    
% A_u0 = 10.8;
G_0 = K_v * K_p * A_u0;

w_r = 702;    % 2 4 1
w_fr = w_r - 700;
omega_0 = w_r - w_fr; % = 0


K = 3;

R = 9;

Tb = T/2;




% FM mode

function [y] = FM_cos(m)
   y = Ac*cos(2*pi*(fc*t + kf*integral(m, 0, t)));
end

function [y] = FM_sin(m)
    % m - function that came from APLL
    y = Ac*sin(2*pi*(fc*t + kf*integral(m, 0, t)));
end

function [y] = fun(y, t, y_0)
    if mod(t, 40) == 0
        return y;
    end
    return y_0;
        
end


function [V_PD] = app(teta_e)
    V_PD = K_p*sin(teta_e);
end

function [Vc] = F(teta_e)
    V_PD = K_p*sin(teta_e);
    Vc = Au0*(1+s*tau_s1)*(1 + s*tau_s2)/(1c +s*tau_p1)/(1 + s*tau_p2);
end

function [teta_0] = app_2(V_C)
    teta_0 = K_V/V_C
end



