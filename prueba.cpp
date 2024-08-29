#include<iostream>

using namespace std;

template <typename T>
class Node{
    T dato;
    Node* next;
public:
    Node(){
        next = NULL;
    }
    
    Node(T d){
        dato = d;
        next = NULL;
    }
    
    ~Node(){
        if constexpr (std::is_pointer<T>::value) {
            delete dato;
        }
    }
    
    T getDato(){
        return dato;
    }
    
    void setDato(T d){
        dato = d;
    }
    
    Node* getNext(){
        return next;
    }
    
    void setNext(Node* n){
        next = n;
    }
};

template <typename T>
class Lista{
    Node<T>* ptr;
    int size;
public:
    Lista(){
        ptr = NULL;
        size = 0;
    }
    
    void add(T d){
        if(ptr == NULL){
            ptr = new Node<T>(d);
        }else{
            Node<T>* temp = ptr;
            while(temp->getNext() != NULL){
                temp = temp->getNext();
            }
            temp->setNext(new Node<T>(d));
        }
        size++;
    }
    
    Node<T>* get(int i){
        if(i >= 0 && i < size){
            int cont=0;
            Node<T>* temp = ptr;
            while(cont < i && temp != NULL){
                temp = temp->getNext();
                cont++;
            }
            return temp;
        }
        
        return NULL;
    }
    
    void print(){
        Node<T>* temp = ptr;
        while(temp != NULL){
            cout<<temp->getDato()<<endl;
            temp = temp->getNext();
        }
    }
    
    int get_size(){
        return size;
    }
    
    void remove(int i){
    // Verificara si el índice es válido
    if (i < 0 || i >= size) {
        return; 
    }
    if (i == 0) {
        Node<T>* temp = ptr;  
        ptr = ptr->getNext(); 
        delete temp;          
    } else {
        Node<T>* temp = ptr;
        for (int j = 0; j < i - 1; j++) {
            temp = temp->getNext();
        }

        Node<T>* nodoAEliminar = temp->getNext(); 
        temp->setNext(nodoAEliminar->getNext());  
        delete nodoAEliminar;  
    }
    size--;
       
    
    }
    
};

class MatrizPublicaciones{
    int** m; //Matriz de presentaciones
    int* v;  //Vector que lleva la cuenta de cuantos artículos hay en cada columna
    int f;   //Filas
    int c;   //Columnas
public:
    MatrizPublicaciones(){
        f = 10;
        c = 10;
        crear_mat();
    }
    
    MatrizPublicaciones(int fi, int co){
        f = fi;
        c = co;
        crear_mat();
    }
    
    void crear_mat(){
        // Crear la matriz [f] [c] e inicializarla en -1
        m = new int*[f];
        for (int i = 0; i < f; i++)
        {
            m[i]=new int[c];
            for (int j = 0; j < c; j++)
            {
                m[i][j]=-1;
            }
        }
        //Crear el vector, de tamaño c, inicializado en 0
        //EL VECTOR QUE CREAMOS ES:
        v=new int[c]();
    }
    
    void print(){
        //recorrer la matriz y escribir el número del artículo o “-“ si el valor es -1
        for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == -1) {
                cout << "- ";
            } else {
                cout << m[i][j] << " ";
            }
        }
        cout << endl;
    }
    }
    
    void addValInColumna(int co, int dato){
        //Añadir un valor en la columna. Qué pasa si esa columna está llena? Hay que
        // crear 1 nuevo espacio (a.k.a. una fila nueva)
        if (v[co] == f) {
            add_fila();
        }
        m[v[co]++][co] = dato;
    }
    
    void add_fila(){
        //Método para añadir una fila a la matriz… 
        //recuerde que debe pasar todos los valores de la vieja a la nueva
        int** new_m = new int*[f + 1];
        for (int i = 0; i < f + 1; i++) {
            new_m[i] = new int[c];
            for (int j = 0; j < c; j++) {
                new_m[i][j] = (i < f) ? m[i][j] : -1;
            }
        }
        delete[] m;
        m = new_m;
        f++;
    }
    
    
};

class Articulo{
    int id;
    Lista<int> autores;
    int area_conocimiento;
    float evaluacion;

public:
    Articulo(){
        id = -1;
        area_conocimiento = -1;
        evaluacion = 0;
    }
    
    Articulo(int idp, int ac, float e){
        //inicializar los atributos con los valores recibidos por parámetro
        id=idp;
        area_conocimiento=ac;
        evaluacion=e;
    }
    
    void add_autor(int ida){
        
        //Añadir un autor a la lista de autores
        autores.add(ida);
    }
    
    int getID(){
        return id;
    }
    
    float get_evaluacion(){
        return evaluacion;
    }
    
    int get_area_conocimiento(){
        return area_conocimiento;
    }
    
    string to_string(){
        string s = std::to_string(id)+" "+std::to_string(area_conocimiento)+" "+std::to_string(evaluacion) +" (";
        int n = autores.get_size();
        for(int i=0; i<n; i++){
            s = s + std::to_string(autores.get(i)->getDato())+",";
        }
        s =  s+")";
        return s;
    }
    
    friend std::ostream& operator<<(std::ostream& os, Articulo& b) {
		return os << b.to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Articulo* b) {
		return os << b->to_string();
	}
	
	friend std::ostream& operator<<(std::ostream& os, Articulo b) {
		return os << b.to_string();
	}
	

};

class LaConference{
    Lista<Articulo*> articulos;
    MatrizPublicaciones matriz;
    int na;
    int nc;
    float min_eval;
    
public:
    LaConference(){
        na = 20;
        nc = 5;
        matriz = MatrizPublicaciones(3,nc);
        min_eval = 2.0f;
        generar_articulos(10);
        print_articulos();
        filtrar_articulos();
        print_articulos();
        generar_matriz();
    }
    
    LaConference(int n, int naa, int ncc, float min){
        na = naa;
        nc = ncc;
        min_eval = min;
        matriz = MatrizPublicaciones(3,nc);
        generar_articulos(n);
        print_articulos();
        filtrar_articulos();
        print_articulos();
        generar_matriz();
    }
    
    void generar_articulos(int n){
        //Generar n artículos
        //Esta fórmula le permite crear evaluaciones entre 0.0 y 5.0
        // ev = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*5.0;
        for (int i = 0; i < n; i++) {
            int area = rand() % nc;
            float ev = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 5.0;
            Articulo* art = new Articulo(i, area, ev);
            int num_autores = 1 + rand() % 5;
            for (int j = 0; j < num_autores; j++) {
                art->add_autor(rand() % na);
            }
            articulos.add(art);
        }
    }
    
    void filtrar_articulos(){
        //Eliminar de la lista todos los artículos con menos de min_eval de puntaje
        // Recuerde: cada vez que elimina un artículo, el tamaño de la lista se reduce…
        // y si elimina el elemento i, cuál es el índice del siguiente elemento a evaluar?
        int initial_size = articulos.get_size();
        int i = 0;

        while (i < articulos.get_size()) {
            Articulo* art = articulos.get(i)->getDato();
            if (art->get_evaluacion() < min_eval) {
                articulos.remove(i);
            } else {
                i++;
            }
        }

        int final_size = articulos.get_size();
        int removed_count = initial_size - final_size;

        cout << "Se eliminaron " << removed_count << " artículos. Quedaron " << final_size << " artículos:" << endl;
        print_articulos();

    }
    
    void print_articulos(){
        for (int i = 0; i < articulos.get_size(); i++) {
        Articulo* art = articulos.get(i)->getDato();
        cout << art->to_string() << endl;
    }
    }
    
    void generar_matriz(){
        for (int i = 0; i < articulos.get_size(); i++) {
            Articulo* art = articulos.get(i)->getDato();
            matriz.addValInColumna(art->get_area_conocimiento(), art->getID());
        }
        cout<<"La matriz de presentación de artículos es:"<<endl;
        matriz.print();
        
    }
    
    
    
};


int main()
{

    srand(time(0));
    
    
    /*//Prueba de Matriz de publicaciones
    //El resultado será una matriz con 9 elementos en la columna 2
    //para lo cual tuvo que haber añadido 5 filas más en el proceso

    MatrizPublicaciones m(5,5);
    
    m.print();
    cout<<endl;
    for(int i=0; i<10; i++){
        m.addValInColumna(2,i);
    }
    
    m.print();*/
    
    
    LaConference c(30, 5, 5, 2.0);
    cout << "Lista inicial de artículos:" << endl;
    c.print_articulos();

    c.filtrar_articulos();

    cout << "Lista de artículos después del filtrado:" << endl;
    c.print_articulos();

    cout << "Matriz de presentación de artículos:" << endl;
    c.generar_matriz();

    return 0;
}
