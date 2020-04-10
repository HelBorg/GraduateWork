function dxdt = apll_attr_nondim_3(G_0, omega_0, t, x)

tau_p1 = 1.65*1e-3;
tau_p2 = 1.65*1e-3;
tau_z1 = 165*1e-6;
tau_z2 = 165*1e-6;
pi = 3.14159265;

a = tau_p1 * tau_p2;
b = tau_p1 + tau_p2 + tau_z1*tau_z2*G_0*cos(1e+3*x(1));
c = 1 + G_0*(tau_z1 + tau_z2)*cos(1e+3*x(1));
d = - tau_z1*tau_z2*G_0*sin(1e+3*x(1));
e = G_0 * sin(1e+3*x(1));
f = omega_0;

% Output vector that represents combined system :
dxdt = zeros(12,1);

% Right-hand side of the Lorenz system :
dxdt(1) = x(2);
dxdt(2) = x(3);
dxdt(3) = (f*1e-9 - e*1e-9 - d*1e+1*x(2)*x(2) -  c*1e-4*x(2) - b*1e-2*x(3))/a;

% Variational matrix :
k = tau_z1*tau_z2*G_0*sin(1e+3*x(1))*1e+1*x(3) ...
    + G_0*(tau_z1 + tau_z2)*sin(1e+3*x(1))*1e-1*x(2) ...
    + tau_z1*tau_z2*G_0*cos(1e+3*x(1))*1e+4*x(2)*x(2) ...
    - G_0*1e-6*cos(1e+3*x(1));
dxdt(4:12) = [0, 1, 0;
               0, 0, 1; 
               k/a, -2*1e+1*d*x(2)/a-(1e-4)*c/a, -1e-2*b/a] ...
                        * [x(4), x(7), x(10); 
                           x(5), x(8), x(11); 
                           x(6), x(9), x(12)];

end