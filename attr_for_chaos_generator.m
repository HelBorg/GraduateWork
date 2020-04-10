tEnd = 1000; 
tStep = 0.1; 
nFactors = 100; 
LEsTol = 1e-2;

acc = 1e-6; RelTol = acc; AbsTol = acc;
odeSolverOptions = odeset('RelTol', RelTol, 'AbsTol', AbsTol);
% check = [ 94.6, 0; 94.0, 0; 88.6, 0; 87.3, 0 ; ...
%     95.8, 700; 95.2, 700; 91.7, 700; 89.8, 700; 88.6, 700; 83.8, 700; ...
%     97.7, 1400; 97.3, 1400; 96.8, 1400; 96.3, 1400; 95.8, 1400];
op = 1;

for i=1:5
    omega_0 = 0;
%     G_0 = db2mag(check(i,1));
%    omega_0 = 0;
  G_0 = 94;
    initPoint = [-pi/4, pi/4, -pi/4];

    tic
    [~, LEs, svdIterations] = computeLEs(@(t, x) apll_attr(G_0, omega_0, t, x), initPoint, tStep, nFactors, LEsTol, odeSolverOptions);
    toc

    disp(omega_0);
    disp(G_0);
    disp(LEs(end, :));
%     check(i, 3:5) = LEs(end, :);
    
%     rer(op,1:3) = LEs(end,:);
%     rer(op,4) = G_0;
%     op = op+1;
end
