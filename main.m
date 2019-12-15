clc
clear

%Smth useful
const T = 2
R = 9

% FM mode

function [y] = FMcos(t)
    Ac = 1 % Amplitude frequency
    fc = 36 % center frequ
    kf = 7.8 % gain of the modulator -> so that RF bandwidth of the FM-DCSK siganl is 17 when the chip rate is 20
    pi = 3.14
    
    sums y;
    y(t) = Ac*cos(2*pi*(fc*t + kf*integral(m(tau), 0, t)))
end

function [y] = FMsin(t)
    Ac = 1 % Amplitude frequency
    fc = 36 % center frequ
    kf = 7.8 % gain of the modulator -> so that RF bandwidth of the FM-DCSK siganl is 17 when the chip rate is 20
    pi = 3.14
    
    sums y;
    y(t) = Ac*sin(2*pi*(fc*t + kf*integral(m(tau), 0, t)))
end