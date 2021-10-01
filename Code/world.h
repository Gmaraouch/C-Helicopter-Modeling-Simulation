

class World
{
	//environment *map;
	helicopter *Helis[2];
	double points;
	Object *objects[4];
	mesh *heli_pad;

public:

	int n; //number of helicopters
	World(int N);
	~World();
	void draw_players();
	void draw_map();
	void calculate();
	void force();
	void set_view_game();
	void display();
	void draw_goal();
	void draw_object();
	int collision();
	void draw_objects();

};