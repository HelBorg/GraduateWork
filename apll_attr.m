function dxdt = apll_attr(G_0, omega_0, t, x)

tau_p1 = 1.65*1e-3;
tau_p2 = 1.65*1e-3;
tau_z1 = 165*1e-6;
tau_z2 = 165*1e-6;
pi = 3.14159265;

c_1 = tau_p1 * tau_p2;
c_2 = tau_p1 + tau_p2 + tau_z1*tau_z2*G_0*cos(x(1));
c_3 = 1 + G_0*(tau_z1 + tau_z2)*cos(x(1));
c_4 = - tau_z1*tau_z2*G_0*sin(x(1));
c_5 = G_0 * sin(x(1));
c_6 = omega_0;

% Output vector that represents combined system :
dxdt = zeros(12,1);

% Right-hand side of the Lorenz system :
dxdt(1) = x(2);
dxdt(2) = x(3);
dxdt(3) = (c_6 - c_5 - c_4*x(2)*x(2) -  c_3*x(2) - c_2*x(3))/c_1;

% Variational matrix :
k = tau_z1*tau_z2*G_0*sin(x(1))*x(3) + G_0*(tau_z1 + tau_z2)*sin(x(1))*x(2) ...
    + tau_z1*tau_z2*G_0*cos(x(1))*x(2)*x(2) - G_0*cos(x(1));
dxdt(4:12) = [0, 1, 0;
               0, 0, 1; 
               k/c_1, -2*c_4*x(2)/c_1-c_3/c_1, -c_2/c_1] ...
                        * [x(4), x(7), x(10); 
                           x(5), x(8), x(11); 
                           x(6), x(9), x(12)];

end