#ifndef PAGINA_H
#define PAGINA_H

#include <string>

class Pagina {
private:
	std::string url, titulo;
	int relevancia;
	
public:
	Pagina(const std::string u, const std::string t, int r);
	void leer();
	const std::string getUrl() const;
	const std::string getTitulo() const;
	int getRelevancia() const;
	void setTitulo(const std::string t);
	void setRelevancia(int r);
	friend bool operator==(const Pagina &p1, const Pagina &p2);
};

#endif
