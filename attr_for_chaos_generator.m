tau_p_1 = 1.65;
tau_p_2 = 1.65;
tau_z_1 = 165;
tau_z_2 = 165;
omega_0 = 0;
G_0 = 90.8;
     


syms Y(t) X(t) Z(t) teta(t)    
a = tau_p_1 * tau_p_2;
b = tau_p_1 + tau_p_2 + tau_z_1*tau_z_2*G_0*cos(teta);
c = 1 + G_0*(tau_z_1 + tau_z_2)*cos(teta);
d = - tau_z_1*tau_z_2*G_0*sin(teta);
e = G_0 * sin(teta);
f = omega_0;
[V] = odeToVectorField(a*diff(teta,3) + b*diff(teta,2) + c*diff(teta) + d*diff(teta)^2 + e == f)

% T = [diff(X) == Y;diff(Y) == Z;diff(Z) == 908000*sin(X)*Y^2 - (36320*sin(X))/1089 - (400*Y*(29964*cos(X) + 1))/1089 - (400*Z*(2472030*cos(X) + 33/10))/1089]
% T = [ Y; Z; 908000*sin(X)*Y^2 - (36320*sin(X))/1089 - (400*Y*(29964*cos(X) + 1))/1089 - (400*Z*(2472030*cos(X) + 33/10))/1089]

M = matlabFunction(V,'vars', {'t','Y'})

sol = ode45(M,[0, 2.94e-01 ],[1 1 1])
% sol = dsolve(T)
% sol.x
% sol.y
fplot(@(x)deval(sol,x,1), [0,2.94e-01])

% syms V_PD
% V_PD = K_p*sin(sol);
% V_c = (-diff(sol,t))/K_p;


    
