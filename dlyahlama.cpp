#include <iostream>
#include <windows.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#define вводрус SetConsoleCP(1251);
#define выводрус SetConsoleOutputCP(1251);
#define Рандом srand(time(NULL));


using namespace std;


int main()
{
	вводрус
		выводрус
		Рандом

		double f, Tpol, FIre, FIrn, FIte, FItn, Htg, Hrg, Tpc, Gt, Gr, * Di, * Hi, D, H; // тут входные данные
	int n;
	// double Ld, Ldba, Ldsph, Ldbs; // первая модель А.1.1
	const double c = 2.998 * pow(10, 8), Re = 6371, Erland = 22.0, Ersea = 80.0, SIGMAland = 0.003, SIGMAsea = 5.0; // КОНСТАНТЫ

	
		cout << "Введите D -общая длина трассы" << "\n";
		cin >> D;
		cin >> n;

		Di = new double[n];

		for (int i = 0, j = 2; i < n; i++, j++)
		{
			Di[i] = (j - 1) * D / n - 1;
			cout << " Di [ " << i << " ] " << Di[i] << endl;
		}

		cout << "Введите H - пиковая высота над уровнем моря" << "\n";
		cin >> H;

		Hi = new double[n];

		for (int i = 0, j = 2; i < n; i++, j++)
		{
			Hi[i] = (j - 1) * H / n - 1;
			cout << " Hi [ " << i << " ] " << Hi[i] << endl;
		}
		// Суша по берегам водоемов - А1 Суша вдали от моря - A2 Море - В


		cout << "Введите f";
		cin >> f;
		cout << "Введите Tpol";
		cin >> Tpol;
		cout << "Введите FIre и FIrn";
		cin >> FIre;
		cin >> FIrn;
		cout << "Введите FIte и FItn";
		cin >> FIte;
		cin >> FItn;
		cout << "Введите Htg и Hrg";
		cin >> Htg;
		cin >> Hrg;
		cout << "Введите Tpc";
		cin >> Tpc;
		cout << "Введите Gt и Gr";
		cin >> Gt; 
		cin >> Gr;

		// Пункт 3.1
		double P, q;
		P = Tpc + 0.00001 * ((50 - Tpc) / 50);
		q = 100 - P;
		//
		
		//Пункт 3.2 скорее всего не нужен
		//double d;
		//d = Di[n - 1];
		
		

		//3.3
		double Hts, Hrs, Hhi, Hlo, Ep;
		Hts = Hi[0] + Htg;
		Hrs = Hi[n-1] + Hrg;
		Hhi = max(Hts, Hrs);
		Hlo = min(Hts, Hrs);
		Ep = (Hhi - Hlo) / D; //d?
		//

		//3.4
		double Nd1km50, Nd1kmp;
		//????

		//3.5
		double Ae, Cp, Ap, Qe;
		Ae = (157 * Re) / (157 + Nd1km50);
		Cp = (157 + Nd1kmp) / (157 * Re);
		if (Cp > 0.000001)
			Ap = 1 / Cp;
		else
			Ap = pow(10, 6);
		Qe = D / Ae; //d?
		//
		
		//3.6
		double Lamda;
		Lamda = pow(10, -9) / f;
		//
		
		//3.7
		double Qtim, Qtr, *Vmaxim, Qtpos, Qrpos;
		Vmaxim = new double[n];
		for (int i = 2; i < n - 1; i++)
		{
			Qtim = max((Hi[i] - Hts) / Di[i] - (500 * Di[i]) / Ae, INT_MIN); // спросить по поводу инт_мина?
		}
		Qtr = (Hrs - Hts) / D - (500 * D) / Ae;
		if (Qtim < Qtr)
		{
			for (int i = 2, j = 0; i < n - 1; i++, j++) // i = 2 ????
			{
				Vmaxim[j] = max((Hi[i] + (500 * Di[i] * (D - Di[i])) / Ae - (Hts * (D - Di[i]) + Hrs * Di[i]) / D) * sqrt((0.0002 * D) / Lamda * Di[i] * (D - Di[i])), INT_MIN);
				if (Vmaxim[j] > H);
				{

				}
			}

		}
		//
	
		//3.8
		
		//

		//3.9
		//значения горизонтальной длины трассы от передатчика до общего объема и от общего объема до приемника

		double Dtcv, Drcv;
		Dtcv = (D * tan(0.001 * Qrpos + 0.5 + Qe) - 0.001 * (Hts - Hrs)) / (tan(0.001 * Qtpos + 0.5 * Qe) + tan(0.001 * Qrpos + 0.5 * Qe));

		if ((Dtcv >= 0) && (Dtcv <= D))
		{
			Drcv = D - Dtcv;
		}
		//Расчеты трассы по дуге большого кругаэ(возможен рофл с переводом единиц в другие)
		//H2
		double Delta_lon, r, FId, Dgc, X1, Y1, Bt2r, FIdrad, pi = 3.14;

		Delta_lon = FIre - FIte;

		r = sin(FItn) * sin(FIrn) + cos(FItn) * cos(FIrn) * cos(Delta_lon);

		FId = acos(r);

		FIdrad = (FId / 180) * pi;//тот самый перевод, не знаю, нужен ли :D

		Dgc = FIdrad * Re;

		X1 = sin(FIrn) - r * sin(FItn);
		Y1 = cos(FItn) * cos(FItn) * sin(Delta_lon);

		if ((abs(X1) < pow(10, -9)) && (abs(Y1) < pow(10, -9)))
		{
			Bt2r = FIre;
		}
		else
			Bt2r = atan(2 * (Y1, X1));
		//H.3Расчет промежуточной точки трассы


		delete[]Di;
		delete[]Hi;
}
