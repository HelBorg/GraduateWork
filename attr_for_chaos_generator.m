omega_0 = 0;
G_0 = db2mag(97.7);
tScale = 1e-3;
x1Scale = 1e-1;
initPoint = [-pi/4, pi/4, -pi/4];

tStep = 0.1/tScale; 
nFactors = 1000; 
LEsTol = 1e-2;

% init_cond = zeros(5, 23);
% init_cond(:, 2) = 0;


acc = 1e-6; RelTol = acc; AbsTol = acc;
odeSolverOptions = odeset('RelTol', RelTol, 'AbsTol', AbsTol);

tic
[~, LEs, svdIterations] = computeLEs(@(t, x) apll_attr_nondim_1(G_0, omega_0, t, x), initPoint, tStep, nFactors, LEsTol, odeSolverOptions);
toc

disp(LEs(end, :));
