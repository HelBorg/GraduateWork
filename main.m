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
G_0 = 10;

K = 3;

R = 9;

A_u0 = 12;
Tb = T/2;
K_v = 12;
K_p = 12;




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



