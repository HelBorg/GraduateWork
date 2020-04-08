clear;

tEnd = 100; 
tStep = 0.1; 
nFactors = tEnd / tStep; 
LEsTol = 1e-2;

acc = 1e-6; RelTol = acc; AbsTol = acc;
odeSolverOptions = odeset('RelTol', RelTol, 'AbsTol', AbsTol);


initPoint = [pi/4, pi/4, 0];
% 16:56
tic
[~, LEs, svdIterations] = computeLEs(@(t, x) apll_attr(t, x), initPoint, tStep, nFactors, LEsTol, odeSolverOptions);
toc

disp(LEs(end, :));
