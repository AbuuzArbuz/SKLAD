#include <iostream>
#include <vector>	

int X_MAX = 11;							//ширина карты
int Y_MAX = 15;							//высота карты

int globalMap[X_MAX][Y_MAX];

struct position{
	int x;
	int y;
}




class Car
{

private:

int car_number;
int map[X_MAX][Y_MAX];								//карта
position cur_pos;									//текущая позиция
position objective;									//цель
std::vector<position> path;
std::vector<position> queue;
int path_found;										//flag if path found
int cur_path_len;

void findPath(){									//ищет путь к objective, трансформирует map, записывает путь в path в ввиде последовательности клеток пути в обратном порядке
	position iter_pos;
	map[cur_pos.x][cur_pos.y] = 1;		
	map[objective.x][objective.y] = 0;

	int found = 0;
	while(!queue.empty()){
		iter_pos = queue.front();
		position pos;
		if(iter_pos == objective){
			found = 1;
			path.push_back(iter_pos);
			break;
		}

		if((iter_pos.x - 1) > 0 && map[iter_pos.x-1][iter_pos.y] == 0){
			pos.x = iter_pos.x-1;
			pos.y = iter_pos.y;
			queue.push_back(pos);
			map[pos.x][pos.y] = map[iter_pos.x][iter_pos.y] + 1;
		}
		if((iter_pos.x + 1) < X_MAX && map[iter_pos.x+1][iter_pos.y] == 0){
			pos.x = iter_pos.x+1;
			pos.y = iter_pos.y;
			queue.push_back(pos);
			map[pos.x][pos.y] = map[iter_pos.x][iter_pos.y] + 1;
		}
		if((iter_pos.y - 1) > 0 && map[iter_pos.x][iter_pos.y-1] == 0){
			pos.x = iter_pos.x;
			pos.y = iter_pos.y-1;
			queue.push_back(pos);
			map[pos.x][pos.y] = map[iter_pos.x][iter_pos.y] + 1;
		}
		if((iter_pos.y + 1) < Y_MAX && map[iter_pos.x][iter_pos.y+1] == 0){
			pos.x = iter_pos.x;
			pos.y = iter_pos.y+1;
			queue.push_back(pos);
			map[pos.x][pos.y] = map[iter_pos.x][iter_pos.y] + 1;
		}
		queue.erase(queue.begin());
	}

	if(found == 1){
		while(map[iter_pos.x][iter_pos.y] != 1){
			position pos;
			if((iter_pos.x - 1) > 0 && map[iter_pos.x-1][iter_pos.y] == map[iter_pos.x][iter_pos.y]-1){
				pos.x = iter_pos.x-1;
				pos.y = iter_pos.y;
			}
			if((iter_pos.x + 1) < X_MAX && map[iter_pos.x+1][iter_pos.y] == map[iter_pos.x][iter_pos.y]-1){
				pos.x = iter_pos.x+1;
				pos.y = iter_pos.y;
			}
			if((iter_pos.y - 1) > 0 && map[iter_pos.x][iter_pos.y-1] == map[iter_pos.x][iter_pos.y]-1){
				pos.x = iter_pos.x;
				pos.y = iter_pos.y-1;
			}
			if((iter_pos.y + 1) < Y_MAX && map[iter_pos.x][iter_pos.y+1] == map[iter_pos.x][iter_pos.y]-1){
				pos.x = iter_pos.x;
				pos.y = iter_pos.y+1;
			}
			iter_pos = pos;
			path.push_back(pos);
		}
		path.push_back(cur_pos);
		path_found = 1;
	}
}


void getGlobMap(){
	int i = 0;
	int j = 0;
	while(i < X_MAX){
		while(j < Y_MAX){
			map[i][j] = globalMap[i][j];			
			++j;
		}
		j = 0;
		++i;
	}

}


void up(){
	cur_pos.y += -1;
}

void down(){
	cur_pos.y += 1;
}

void left(){
	cur_pos.x += -1;
}

void right(){
	cur_pos.x += 1;
}




public:

Car(int x_obj, int y_obj, int x_cur, int y_cur, int car_num){				//конструктор класса
	getGlobMap();
	setObjective(x_obj, y_obj);
	setPos(x_cur, y_cur);
	car_number = car_num;
	position nulPos;
	nulPos.x = 0;
	nulPos.y = 0;
	queue.push_back(nulPos);												//устанавливаем начальную точку в очередь для поиска пути
	path_found = 0;
	findPath();
	cur_path_len = 0;
}
			
void setObjective(int x0, int y0){					//устанавливает точку, куда нужно ехать
	objective.x = x0;	
	objective.y = y0;							
}

void setPos(int x1, int y1){						//устанавливает текущую позицию погрузчика
	cur_pos.x = x1;
	cur_pos.y = y1;
}

void getPos(int *pos){								//записывает текущую позицию в pos*
	pos[0] = cur_pos.x;
	pos[1] = cur_pos.y;
}

void writePos(){
	std::cout<<"X: "<<cur_pos.x<<"\n";
	std::cout<<"Y: "<<cur_pos.y<<"\n";
}

void go(){											//погрузчик делает следующий шаг	
	position next_step = path[path.size()-1 - cur_path_len];
	++cur_path_len;
	if(next_step == objective){
		objective.x = X_MAX-1;
		objective.y = Y_MAX-1;
		findPath();
	}


	if(next_step.x != cur_pos.x){
		if(next_step.x < cur_pos.x){
			left();
		}else{
			right();
		}
	}else{
		if(next_step.y < cur_pos.y){
			up();
		}else{
			down();
		}
		
	}
	writePos();
}


}







