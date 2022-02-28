#ifndef PHILOSOPHER_PHILOSOPHER_H
#define PHILOSOPHER_PHILOSOPHER_H

#include <mutex>

#define NB_OF_MEALS 5

enum actions {
	GRAB_FORK,
	RELEASE_FORK,
	EAT,
	THINK
};

class philosopher {
public:
	philosopher(const int& new_id, std::mutex *printer);

	void		eat(std::mutex* first, std::mutex* second);
	void		think();
	int			getId();
	int			getMealCount();
	void		print(int action);
	std::mutex*	getPrinterMtx();

private:
	int			id;
	int			meal_count;
	std::mutex	*printer_mtx;
};

#endif //PHILOSOPHER_PHILOSOPHER_H
