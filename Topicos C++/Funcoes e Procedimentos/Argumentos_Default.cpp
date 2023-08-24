// Exemplifica o uso de valores default para argumentos e protótipos de funções

#include <iostream>
using namespace std;

// VolCubo(2) configura todos os parametros como == 2
// Os valores dos parametros sao definidos em sequencia, nao sendo possivel isolar os parametros
// entao VolCubo(2) define apenas o primeiro parametro como 2 e o restante default
float VolCubo(float length = 1, float width = 1, float height = 1)
{
	printf("%f %f %f\n", length, width, height);
	return (length * width * height);
}

int main()
{
	float length = 0;
	float width = 0;
	float height = 0;
	float VolPadrao = 0;
	float Vol = 0;

	cout << "\nCálculo de volume\n";

	cout << "Qual o comprimento? >> ";
	cin >> length;

	cout << "Qual a largura? >> ";
	cin >> width;

	cout << "Qual a altura? >> ";
	cin >> height;

	Vol = VolCubo(length, width, height);
	cout << "Volume desejado = " << Vol << endl;

	VolPadrao = VolCubo(2);
	cout << "Volume Padrão   = " << VolPadrao << endl;

	system("pause");

	return 0;
}
