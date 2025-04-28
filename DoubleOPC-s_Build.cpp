// Oscar G. Rodriguez
// Diego G. Marengo

// Referencia de los componentes: https://www.newegg.com/?srsltid=AfmBOorZ_cfZsRjtNu5Wx03XT8K9GEee1PrbVBtgBPrxqfQ4QUPCyV9H
/* Referencias para aprender a utilizar ofstream: https://youtu.be/MuzWtDutjc8?si=CBt7I9M1YVechbyi
https://youtu.be/InoDNAISX_4?si=eEZFccOC49-al-ag */
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

//Oscar G. Rodriguez
const int numOpc = 4;
// Arrays de componentes y sus precios
string gabinetes[numOpc] = {
    "SAMA SV02 - Mid Tower ATX",
    "Valkyrie VK02 - Mid Tower ATX",
    "Zalman s3 - Mid Tower ATX",
    "Corsair FRAME 400D RS White Steel / Tempered Glass - Mid Tower ATX"
};
float gabinetePrecio[numOpc] = { 159.99, 129.90, 57.99, 99.99 };
//************************************************************************************************
string placaMadre[numOpc] = {
    "ASUS TUF GAMING Z690-PLUS WIFI D4 LGA 1700 DDR4 128GB ATX Motherboard",
    "ASUS TUF Gaming Z690-PLUS D4 LGA 1700 DDR4 ATX Motherboard",
    "MSI PRO Z690-A DDR4 LGA 1700 Intel Z690 SATA 6Gb/s ATX Intel Motherboard",
    "MSI PRO Z690-A DDR4 Intel LGA 1700 Z690 ATX M.2 Desktop Motherboard ATX"
};
float placaPrecio[numOpc] = { 298.00, 260.40, 217.17, 99.99 };
//************************************************************************************************
string cpu[numOpc] = {
    "Intel Core i5-12400F - Core i5 12th Gen Alder Lake 6-Core 2.5 GHz LGA 1700 65W Desktop Processor)",
    "Intel Core i7-12700K - Core i7 12th Gen Alder Lake 12-Core (8P+4E) 3.6 GHz LGA 1700 125W Intel UHD Graphics 770 Desktop Processor",
    "Intel Core i5-13400 Desktop Processor 10 cores (6 P-cores + 4 E-cores) 20MB Cache, up to 4.6 GHz - Box",
    "Intel Core i9-12900K - Core i9 12th Gen Alder Lake 16-Core (8P+8E) 3.2 GHz LGA 1700 125W Intel UHD Graphics 770 Desktop Processor"
};
float cpuPrecio[numOpc] = { 184.00, 449.99, 160.99, 649.99 };
//************************************************************************************************
string ram[numOpc] = {
    "Corsair Vengeance LPX 16GB (2x8GB) DDR4 DRAM 3200MHz C16 Memory Kit - Black - 16 GB (2 x 8 GB) ",
    "G.SKILL Ripjaws V Series 32GB (2 x 16GB) 288-Pin PC RAM DDR4 3600 (PC4 28800) ",
    "CORSAIR Vengeance RGB Pro 32GB (2 x 16GB) 288-Pin PC RAM DDR4 3600 (PC4 28800)",
    "TEAMGROUP T-Force Xtreem ARGB 3600MHz CL18 32GB (2x16GB) PC4-28800 Dual Channel DDR4 DRAM"
};
float ramPrecio[numOpc] = { 29.99, 56.99, 92.99, 225.09 };
//************************************************************************************************
string gpu[numOpc] = {
    "ASUS GeForce RTX 4060 LP BRK OC Edition 8GB GDDR6 ",
    "GIGABYTE GeForce RTX 4070 WINDFORCE OC V2 12GB GDDR6",
    "ASRock Radeon RX 6700 XT Challenger D Gaming Graphic Card, 12GB GDDR6",
    "ASRock Radeon RX 6600 Challenger D 8GB GDDR6 "
};
float gpuPrecio[numOpc] = { 422.67, 749.00, 778.70, 279.99 };
//************************************************************************************************
string storage[numOpc] = {
    "SAMSUNG 990 PRO 2TB SSD, PCIe Gen4 M.2 2280, Seq. Read Speeds Up-to 7,450MB/s ",
    "WD_BLACK 2TB SN850X NVMe Internal Gaming SSD Solid State Drive - Gen4 PCIe, M.2 2280",
    "KingSpec M2 SSD NVMe 1TB M.2 2280 PCIe Gen 3.0X4 SSD Internal Solid State Drive",
    "Corsair MP700 Elite M.2 2280 2TB PCI-Express 5.0 x4 3D TLC Internal Solid State Drive (SSD) Up to 10000 MB/s"
};
float storagePrecio[numOpc] = { 199.99, 159.99, 73.99, 189.99 };
//************************************************************************************************
string cooling[numOpc] = {
    "Phanteks D30-140 DRGB PWM FAN 3Pack, Reverse Airflow Model, Premium D-RGB Performance Fans",
    "Phanteks D30-140 DRGB PWM Fan, Reverse Airflow Model, Premium D-RGB Performance Fan",
    "NZXT Kraken RGB 360mm - RL-KR360-W1 - AIO RGB CPU Liquid Cooler",
    "Cooler Master MasterLiquid 360 Atmos ARGB Close-Loop AIO Liquid Cooler"
};
float coolingPrecio[numOpc] = { 118.00, 43.99, 219.99, 149.99 };
//************************************************************************************************
string fuente[numOpc] = {
    "RAIDMAX XT Series RX-400XT 400 W ATX12V / EPS12V 80 PLUS BRONZE Certified Non-Modular Power Supply",
    "CORSAIR RMx Series RM850x ATX Power Supply - Fully Modular - ATX 3.1",
    "SEASONIC 750W 80+ Gold Full-Modular Nvidia RTX 30/40 Super & AMD GPU Compatible Power Supply",
    "Thermaltake GF1 (2024) Fully Modular ATX 750W Power Supply - 80 PLUS Gold"
};
float fuentePrecio[numOpc] = { 39.99, 149.99, 162.71, 99.99 };
//************************************************************************************************
// Funcion para mostrar informacion de los componentes
void mostrarInfComponentes() {
    string componentes[] = {
       "1. Gabinete ATX: Debes verificar que los componentes encajen con el gabinete.",
       "2. Placa madre: Verifica que procesadores y RAM son compatibles.",
       "3. Procesador o CPU: Define la potencia y el rendimiento de la PC. Es el cerebro de la PC",
       "4. Memoria RAM: Afecta la velocidad y multitarea del sistema.",
       "5. Tarjeta grafica o GPU: Esencial para juegar con alta calidad.",
       "6. Almacenamiento: Afecta la rapidez de carga de juegos y programas. Preferiblemente un NVME M.2 para mayor rapidez.",
       "7. Sistema de enfriamiento: Puede ser por aire o liquido, dependiendo de la necesidad.",
       "8. Fuente de poder: Debe ser suficiente para alimentar todos los componentes."
    };
    for (int i = 0; i < 8; i++) {
        cout << componentes[i] << endl;
    }
}
/**************************************************************************************************************/
//[OpenAI] ([2024]) [GPT-4o] Recuperado desde: [https://chatgpt.com/]
// Funcion para elegir entre los 4 tipos de un solo componente del PC
// La variable string& elegir modifica directamente la variable original que se pasa como argumento, en lugar de crear una copia.
float elegirComponentes(string opciones[], float precios[], int numOpc, string componente, string& elegir) {
    int eleccion;
    do {
		// Limpiar la pantalla del menu principal a la hora de mostrar el menu de componentes
        system("cls");
        cout << "Eliga un " << componente << ":" << endl;

		// muestra las opciones de componentes y sus precios
        for (int i = 0; i < numOpc; i++) {
            cout << i + 1 << ". " << opciones[i] << " - $" << precios[i] << endl;
        }
        cin >> eleccion;

        // Limpiar la pantalla a la hora de mostrar el error
        system("cls");
        if (eleccion < 1 or eleccion > numOpc) {
            cout << "Invalido. Por favor, seleccione una opcion entre 1 y " << numOpc << "." << endl;
            Sleep(5000);
        }

    } while (eleccion < 1 or eleccion > numOpc);
	// Se guarda la eleccion del componente en la variable "elegir" y el - 1 es para que no elija la opcion incorrecta
    elegir = opciones[eleccion - 1];
    return precios[eleccion - 1];
}
/* Funcion para llamar a "elegirComponentes" para los ocho tipos de componentes del PC,
imprimir la lista de componentes elegidos y guarda la lista en un archivo .txt */
void pcBuild() {
    float precioTotal = 0;
    string elegirCase, elegirPlaca, elegirCpu, elegirRam, elegirGpu, elegirStorage, elegirCooling, elegirFuente;

    precioTotal += elegirComponentes(gabinetes, gabinetePrecio, numOpc, "gabinete", elegirCase);
    precioTotal += elegirComponentes(placaMadre, placaPrecio, numOpc, "placa madre", elegirPlaca);
    precioTotal += elegirComponentes(cpu, cpuPrecio, numOpc, "Procesador", elegirCpu);
    precioTotal += elegirComponentes(ram, ramPrecio, numOpc, "Memoria RAM", elegirRam);
    precioTotal += elegirComponentes(gpu, gpuPrecio, numOpc, "Tarjeta grafica", elegirGpu);
    precioTotal += elegirComponentes(storage, storagePrecio, numOpc, "almacenamiento", elegirStorage);
    precioTotal += elegirComponentes(cooling, coolingPrecio, numOpc, "sistema de enfriamiento", elegirCooling);
    precioTotal += elegirComponentes(fuente, fuentePrecio, numOpc, "fuente de poder", elegirFuente);
    /**************************************************************************************************************/

	//Diego G. Marengo
    // Imprime la lista de los componentes elegidos
    cout << "Su PC build es:" << endl;
    cout << "Gabinete: " << elegirCase << endl;
    cout << "Placa Madre: " << elegirPlaca << endl;
    cout << "Procesador: " << elegirCpu << endl;
    cout << "Memoria RAM: " << elegirRam << endl;
    cout << "Tarjeta grafica: " << elegirGpu << endl;
    cout << "Almacenamiento: " << elegirStorage << endl;
    cout << "Enfriamiento: " << elegirCooling << endl;
    cout << "Fuente de poder: " << elegirFuente << endl;
    cout << "**********************************************************************" << endl;
    cout << "El precio total de su PC es: $" << precioTotal << endl;
    cout << "**********************************************************************" << endl;

    // Crea un archivo.txt de la lista de componentes elegidos
    ofstream archivo("Mi_PC_build.txt");
    if (archivo.is_open()) {
        archivo << "----------- Mi PC Build ----------- " << endl;
        archivo << "Gabinete: " << elegirCase << endl;
        archivo << "Placa Madre: " << elegirPlaca << endl;
        archivo << "Procesador: " << elegirCpu << endl;
        archivo << "Memoria RAM: " << elegirRam << endl;
        archivo << "Tarjeta grafica: " << elegirGpu << endl;
        archivo << "Almacenamiento: " << elegirStorage << endl;
        archivo << "Enfriamiento: " << elegirCooling << endl;
        archivo << "Fuente de poder: " << elegirFuente << endl;
        archivo << "**********************************************************************" << endl;
        archivo << "Precio total: $" << precioTotal << endl;
        archivo.close();
        cout << "Su PC build se guardo en: Mi_PC_build.txt" << endl;
    }
    else {
        cout << "No se pudo crear el archivo." << endl;
    }
} 
// Bloque principal para imprimir el menu y llamar a las funciones
int main() {
    int menuOpc;
    do {
        cout << "---------- Bienvenido a DoubleOPC-s_Build ----------" << endl;
        cout << "Escoga una de las siguientes opciones entre 1 y 4: " << endl;
        cout << "1. Conocenos: " << endl;
        cout << "2. Informacion sobre los componentes que debes tener en tu PC: " << endl;
        cout << "3. Construye su propia PC: " << endl;
        cout << "4. Salir" << endl;
        cin >> menuOpc;

        switch (menuOpc) {
            
        case 1:
            cout << "**********************************************************************" << endl;
            cout << "Estamos comenzando en este mundo sobre computadoras y queremos hacer todo lo posible para ayudarlos." << endl;
            system("pause");
            system("cls");
            break;

        case 2:
            cout << "**********************************************************************" << endl;
            mostrarInfComponentes();
            system("pause");
            system("cls");
            break;

        case 3:
            pcBuild();
            system("Mi_PC_build.txt");
            system("pause");
            system("cls");
            break;

        case 4:
            cout << "**********************************************************************" << endl;
            cout << "Gracias por visitar DoubleOPC-s_Build. Hasta luego!" << endl;
            Sleep(4000);
            system("cls");
            break;

        default:
            system("cls");
            cout << "Invalido. intentelo de nuevo." << endl;
            Sleep(3000);
            system("cls");
            break;

        }
    } while (menuOpc != 4);

    return 0;
}

