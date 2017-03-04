#include <iostream>
using namespace std;

#define MAX 30 // Nr maxim de orase
#define MIN 0 //Valoarea initiala pt minim

int n=5; //nr de orase
int dist[MAX][MAX]; //Matricea cu distantele dintre orase
int drum[MAX]; //Drumul comis voiajorului, contine indexul oraselor vizitate
int vizitat[MAX]; //Vector care memoreaza ce orase am vizitat, vizitat[i]=1 daca orasul a fost vizitat altfel 0.

void afisare_drum(int drum_scurt[100],int cost_min);

void alege(int ultim, int *min, int *j_min){
	int j;
	//Se cauta distanta maxima pana la un oras ce nu a fost vizitat;
	for(j=0;j<n;j++){
		if(!vizitat[j]){
			*min = 0;
			if(dist[ultim][j]>*min){
				*min = dist[ultim][j];
				*j_min=j;
			}
		}
		
	}
}

void distante(){//afisam matricea ce am citit-o din fisier
	cout << "Distanta intre orase" << endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

void traseu(){
	int index,min,j_min;
	int nr, cost;
	int cost_min=MIN;
	int drum_min[MAX];
	for(index = 0;index<n;index++){
		cout << " Pornim din punctul " << index+1 << endl;
		min=MIN;
		j_min=MIN;
		for (int i=0;i<n;i++){
			vizitat[i]=0; //Initial nici un punct nu a fost vizitat
			drum[i]=0;
		}//initial suntem in orasul cu nr 0.
		drum[0]=index;
		vizitat[index]=1;
		nr=1;
		cost=0;
		//parcurgem restul de n-1 orase
		for(int i=0;i<n-1;i++){
			//alegem urmatorul oras;
			alege(drum[nr-1],&min,&j_min);
			//se parcurge drumul cel mai lung gasit intre orase
			cout << "Legatura intre " << drum[nr-1]+1 << " , " << j_min+1 << " cu costul " << min << endl;
			drum[nr]=j_min;
			vizitat[j_min]=1;
			nr++;
			cost+=min;
		}
		//Mergem de la ultimul oras vizitat la primul si contorizam costul total
		//cost += dist[drum[n-1]][index];
		//Afiseaza drumul ales
		cout << "Drumul are cost " << cost << " si este: " << endl;
		for(int i=0;i<n;i++){
			cout << drum[i]+1 << " ";
		}
		cout << endl << endl << endl << index+1;
		if(cost > cost_min){
			for(int i=0;i<n;i++){
				drum_min[i]=drum[i];
			}
			cost_min=cost;
		}
	}
	afisare_drum(drum_min,cost_min);
}

void afisare_drum(int drum_scurt[100],int cost_min){
	cout << "Diametrul grafului: " << drum_scurt[0] << " are costul " << cost_min << " si este : " << endl;
	for(int i=0;i<n;i++){
		cout << drum_scurt[i]+1 << " ";
	}	
}

void get_graph(){
	int i,j;
	for(i=0;i<n;i++){//citim din fisier matricea distantelor
		for(j=0;j<n;j++){
			cout << "Introduceti noduri: " << i << " " << j<< endl;
			cin >> dist[i][j];
		}
	}
}

int main(){
	get_graph();
	distante();
	traseu();


	system("pause");
	return 0;
}