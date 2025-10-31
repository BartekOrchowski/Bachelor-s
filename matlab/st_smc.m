%% Wyczyść środowisko pracy MATLAB
clear; 
close all; 
clc;
% Usuwa wszystkie zmienne, zamyka okna wykresów i czyści konsolę.
% Dzięki temu unikamy błędów wynikających z pozostałości po poprzednich uruchomieniach.

%% Parametry symulacji
ts = 1e-4;           % Krok czasowy (zgodny z ustawieniem fixed-step w Simulinku)
sim_time = 2;        % Całkowity czas trwania symulacji [s]

%% Parametry obiektu sterowania (model silnika DC)
Te = 0.001;          % Stała czasowa części elektrycznej silnika [s]
Tm = 0.2;            % Stała czasowa części mechanicznej silnika [s]
% Parametry te opisują dynamikę modelu silnika – odpowiednio jego obwodu elektrycznego i mechanicznego.

%% Uruchomienie symulacji modelu w Simulinku
out = sim('sim_st_smc', 'StopTime', num2str(sim_time));

%% Pobranie danych z wyników symulacji
t = out.tout;                     % wektor czasu
w = squeeze(out.w.Data);          % prędkość rzeczywista silnika
w_ref = squeeze(out.w_ref.Data);  % prędkość zadana (wartość referencyjna)
e = squeeze(out.e.Data);          % błąd regulacji: e = w_ref - w
de = squeeze(out.de.Data);        % pochodna błędu (zmiana błędu w czasie)
u = squeeze(out.u.Data);          % sygnał sterujący (wynik działania regulatora ST-SMC)

%% Rysowanie wyników symulacji

% Wykres prędkości rzeczywistej i zadanej 
figure(1);
plot(t, w, 'LineWidth', 1.3); hold on;
plot(t, w_ref, 'LineWidth', 1.3);
grid on;
xlabel('t [s]'); ylabel('\omega [p.u.]');
legend('\omega', '\omega_{ref}');
title('Prędkość rzeczywista i zadana');
% Wykres pozwala ocenić, jak dokładnie układ nadąża za wartością zadaną.

% Portret fazowy (błąd vs pochodna błędu)
figure(2);
plot(e, de, 'LineWidth', 1.3);
grid on;
xlabel('e'); ylabel('de');
title('Portret fazowy (e vs de)');
% W tym wykresie widać trajektorię stanu układu w przestrzeni błędu i jego pochodnej.
% Dobrze zaprojektowany SMC powinien powodować zbieżność trajektorii do punktu (0,0).

% Wykres sygnału sterującego
figure(3);
plot(t, u, 'LineWidth', 1.3);
grid on;
xlabel('t [s]');
ylabel('u [p.u.]');
title('Sygnał sterujący u(t)');
% Tutaj można zaobserwować działanie algorytmu super-twisting: 
% sygnał u powinien być płynniejszy niż w klasycznym SMC, z mniejszym „chatteringiem”.
