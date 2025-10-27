%% clear the workspace
clear; close all; clc;

%% parameters of simulation
ts = 1e-4;           % krok czasowy (zgodny z fixed-step)
sim_time = 2;        % czas symulacji [s]

%% parameters of the object (model silnika DC)
Te = 0.001;          % stała elektryczna
Tm = 0.2;            % stała mechaniczna

%% parameters of ST-SMC & Fuzzy
% Stałe wzmocnienia dla bazowego ST-SMC (u_ST). Są mniejsze, bo AI pomoże.
k1_st = 1;         % Bazowe k1 (mniejsze niż wcześniej)
k2_st = 0.1;       % Bazowe k2 (mniejsze niż wcześniej)

up_lim = 10;         % górne ograniczenie sterowania
dn_lim = -up_lim;    % dolne ograniczenie sterowania

% Wczytanie pliku FLC (musi być wcześniej stworzony w 'fuzzy')
% Plik FIS musi być w folderze roboczym!
fis = readfis('ai_smc_fuzzy.fis');
disp(['Inputs: ', num2str(numel(fis.input)), ', Outputs: ', num2str(numel(fis.output))]);

assignin('base','ai_smc_fuzzy',fis);

set_param('sim_ai_smc/Fuzzy Logic Controller','fisName','ai_smc_fuzzy');
set_param('sim_ai_smc','SimulationCommand','update');
%fuzzy_controller = 'ai_smc_fuzzy.fis';
%fis_data = readfis('ai_smc_fuzzy.fis');
%disp(['Liczba wejść w pliku FIS: ', num2str(size(fis_data.input, 2))]);
load_system('sim_ai_smc'); % Jeśli chcesz załadować model przed symulacją

%% start of simulation
out = sim('sim_ai_smc', 'StopTime', num2str(sim_time));

%% extract data
t = out.tout;
w = squeeze(out.w.Data);          % prędkość rzeczywista
w_ref = squeeze(out.w_ref.Data);  % prędkość zadana
e = squeeze(out.e.Data);          % błąd e = w_ref - w
de = squeeze(out.de.Data);        % pochodna błędu (tylko do wykresów)
u= squeeze(out.u.Data);           % CAŁKOWITE sterowanie (u_ST + u_fuzzy)

%% plots
figure(1);
plot(t, w, 'LineWidth', 1.3); hold on;
plot(t, w_ref, 'LineWidth', 1.3);
grid on;
xlabel('t [s]'); ylabel('\omega [p.u.]');
legend('\omega', '\omega_{ref}');
title('Prędkość rzeczywista i zadana');

figure(2);
plot(e, de, 'LineWidth', 1.3);
grid on;
xlabel('e'); ylabel('de');
title('Portret fazowy (e vs de)');

figure(3); 
plot(t, u); 
title('u - sterowanie ');