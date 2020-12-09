#ifndef _NETWORK_H
#define _NETWORK_H

#include <vector>

#define K 10
#define NUMOFSECTIONS 2
#define GB 1 // Guardband
#define NUMOFSPECTRALSLOTS 128
// #define NUMOFSPECTRALSLOTS 16
#define MAX_DATASIZE_REQUEST 200 
// #define MAX_DATASIZE_REQUEST 50 
#define BW_SPECSLOT 12.5

/*** opções do ResourceAssignment.cpp ***/
#define DEBUG_print_resource_state_on_the_path
#define DEBUG_print_AvailableSpecSlots
#define DEBUG_print_PotentialSections_and_PC
#define DEBUG_print_SortedSections
#define DEBUG_collect_EventID_of_blocked_requests //need to collaberate with debug_print_eventid_of_blocked_requests

#define DISPLAY_available_path
#define DISPLAY_path_order
#define DISPLAY_selected_path
#define DISPLAY_metrics
#define PRINT_allocation_block_release


/*** Opções do TrafficGenerator.cpp ***/
#define DEBUG_print_new_built_Event

using namespace std;

class RoutingTable;

class Network {
	public:
		/*** Funções ***/  
		void init ();
		void simulation ();


		/*** Variaveis ***/ 
		// Importando as  Variaveis   
		char FileName[500];
		double Lambda, Mu;
		long long NumofRequests;
		unsigned int NumofCores;
		int SectionNumLimitation;
		double a, b, c;


		// Topologia das Variaveis
		unsigned int NumofNodes; 
		vector< vector<double> > NodesWeight;
		vector<int> NumofAjacentNodes;
		vector< vector< vector<int> > > DRoutingTable;
		vector< vector< vector< vector<int> > > > routingTable;

		// Metricas por requisição
		double TotalHoldingTime;
		long long TotalTranspondersUsed;
		long long TotalCoresUsed;
		long long TotalGBUsed;
		double AvgHoldingTime;
		double AvgTranspondersUsed;
		double AvgGBUsed;
		double AvgCoresUsed;	


		// Metricas para medir a fragmentação 
		long long TotalDataSize;
		long long TotalSSUsed;
		long long TotalSSOccupied;

		double AvgIntFrag;
		double AvgExtFrag;
		double AvgHybridFrag;

		// cronometro e contador
		long long RequestCounter; // Gerador de numeros por requisição
		long long NumofAllocatedRequests;
		long long NumofDoneRequests; // As solicitações que forem alocadas e liberadas com sucesso, ou bloqueadas serão consideradas como DoneRequests
		long long NumofFailedRequests; // Numero de solicitações bloqueadas
		long long NumofTransponders; // Numero de transponders usados em um momento especifico
		long long MaxNumofTransponders; // Numero maximo de transponders para um unica simulação
		int NumofSections;
		int MaxNoH, MinNoH;
		int MaxNumofSections;
		double SystemClock;
		

		// Variaveis de recursos
		vector< vector< vector< vector<bool> > > > SpectralSlots;

		// Variaveis de Depuração
		vector<int> BlockedRequests;
		
		
	private:
};

#endif
