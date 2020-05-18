clc
clear
tScale = 1e-3;
x1Scale = 1e-1;
initPoint = [-pi/4, pi/4, -pi/4];

tStep = 0.1/tScale; 
nFactors = 1000; 
LEsTol = 1e-2;

init_cond = zeros(25, 5);
init_cond(:, 2) = 1400;
init_cond(:, 1) = [97.7 97.3 96.8 96.3 95.8 95.2 94.6 94 93.3 ...
    92.5 91.7 90.8 89.8 88.6 87.3 85.7 84.7 83.8 82.5 81.3 80.3 79.3 78.6 77.7 71.7];
% init_cond(:,2) = [0 175 350 525 700 875 1050 1225 1400];
% init_cond(:, 1) = 84.7;

acc = 1e-6; RelTol = acc; AbsTol = acc;
odeSolverOptions = odeset('RelTol', RelTol, 'AbsTol', AbsTol);

for i = 1:25
    omega_0 = init_cond(i,2)
    G_0 = db2mag(init_cond(i,1));
    init_cond(i,1)
    tic
    [~, LEs, svdIterations] = computeLEs(@(t, x) apll_attr_nondim_1(G_0, omega_0, t, x), initPoint, tStep, nFactors, LEsTol, odeSolverOptions);
    toc

    disp(LEs(end, :));
    disp(i);
    init_cond(i, 3:5) = LEs(end, :);
end
