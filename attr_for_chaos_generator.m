tau_p_1 = 1.65;
tau_p_2 = 1.65;
tau_z_1 = 165;
tau_z_2 = 165;
omega_0 = 0;
% syms G_0;
G_0 = 90.8;

syms Y(t) X(t) Z(t) teta(t)    
a = tau_p_1 * tau_p_2;
b = tau_p_1 + tau_p_2 + tau_z_1*tau_z_2*G_0*cos(teta);
c = 1 + G_0*(tau_z_1 + tau_z_2)*cos(teta);
d = - tau_z_1*tau_z_2*G_0*sin(teta);
e = G_0 * sin(teta);
f = omega_0;
[V] = odeToVectorField(a*diff(teta,3) + b*diff(teta,2) + c*diff(teta) + d*diff(teta)^2 + e == f)
M = @(t,Y)[Y(2);Y(3);sin(Y(1)).*(-3.335169880624426e+1)+sin(Y(1)).*Y(2).^2.*9.08e+5-Y(2).*(cos(Y(1)).*2.9964e+4+1.0).*3.673094582185491e-1-Y(3).*(cos(Y(1)).*2.47203e+6+3.3e+1./1.0e+1).*3.673094582185491e-1]
sol = ode45(M,[0 1],[1 1 1])

% Draw bifurcation diagram
% fun = @(x,r) r*x*(1-x); 
% x0 = .4; a0 = 0; a1 = 4; N = 100; L = 50;
% mat = bifurcation(fun,x0,a0,a1,N,L)

% 
% syms Y(t) X(t) Z(t) teta(t)    
% a = tau_p_1 * tau_p_2;
% b = tau_p_1 + tau_p_2 + tau_z_1*tau_z_2*G_0*cos(teta);
% c = 1 + G_0*(tau_z_1 + tau_z_2)*cos(teta);
% d = - tau_z_1*tau_z_2*G_0*sin(teta);
% e = G_0 * sin(teta);
% f = omega_0;
% [V] = odeToVectorField(a*diff(teta,3) + b*diff(teta,2) + c*diff(teta) + d*diff(teta)^2 + e == f)
% 
% % T = [diff(X) == Y;diff(Y) == Z;diff(Z) == 908000*sin(X)*Y^2 - (36320*sin(X))/1089 - (400*Y*(29964*cos(X) + 1))/1089 - (400*Z*(2472030*cos(X) + 33/10))/1089]
% % T = [ Y; Z; 908000*sin(X)*Y^2 - (36320*sin(X))/1089 - (400*Y*(29964*cos(X) + 1))/1089 - (400*Z*(2472030*cos(X) + 33/10))/1089]
% 
% M = matlabFunction(V,'vars', {'t','Y'})
% 
% sol = ode45(M,[0 10],[10 10 10])
% % sol = dsolve(T)
% % sol.x
% % sol.y
% figure
% fplot(@(x)deval(sol,x,1), [2.96e-01, 5.906e-01])
% 
% % syms V_PD
% % V_PD = K_p*sin(sol);
% % V_c = (-diff(sol,t))/K_p;
% 
% toc
% 
% 
%     
