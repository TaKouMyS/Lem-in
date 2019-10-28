#include "lem-in.h"

void	set_weights(t_farm *f)
{
	int i;

	i = -1;
	while (++i < f->room_nb)
		f->id_table[i]->weight = 2147483647;
	f->start->weight = 0;
}

void	switch_flows(t_room *next, t_room *current, t_queue *q, t_farm *f)
{
		q->flow[f->id_table[q->prev[next->id]]->id][next->id] = 0;
		q->flow[next->id][f->id_table[q->prev[next->id]]->id] = 0;
		if (q->flow[current->id][next->id] == -1)
		{
			q->flow[current->id][next->id] = 0;
			q->flow[next->id][next->id] = 0;
		}
		else
		{
			q->flow[current->id][next->id] = 1;
			q->flow[next->id][next->id] = -1;
		}
		
}

int		compare_weights(t_room *next, t_room *current, t_queue *q, t_farm *f)
{
	int pos;

    if (q->flow[current->id][next->id] == 1)
        return (0);
	if (q->flow[current->id][next->id] == -1)
		pos = current->weight - 1;
	else
		pos = current->weight + 1;
  //  if(next != f->start)
 //   {
//    printf("%s is linked to %s, weight is %d ", next->name, f->id_table[q->prev[next->id]]->name, next->weight);
//    printf("but could link %s, for weight of %d\n", current->name, pos);}
	if (pos < next->weight && next->weight != 2147483647)
	{
		next->weight = pos;
		return (1);
	}
	return (0);
}

int		check_loops(t_room *next, t_room *current, t_queue *q, t_farm *f)
{
	int i;
	int visit[f->room_nb];
	int j;

	i = q->prev[current->id];
	j = -1;
	while (++j != f->room_nb)
		visit[j] = 0;
//	printf(" start = %d end %d max rooms %d\n", f->start->id, f->end->id, f->room_nb);
	while (i != -1 && i != f->start->id && i != f->end->id)
	{
		i = q->prev[i];
		if (visit[i] == 1)
			return (0);
		visit[i] = 1;
//		printf("i =%d next i =%d\n", i, q->prev[i]);
	}
	if (i != f->start->id && i != f->end->id)
		return (0);
	return (1);
}

int		check_weights(t_room *next, t_room *current, t_queue *q, t_farm *f)
{
	if (compare_weights(next, current, q ,f) == 0) 
		return (0);
	if (next == f->start)
		return (0);
	if (check_loops(next, current, q, f) == 0)
	{
	//	printf("LOOP\n");
		return (0);
	}
		switch_flows(next, current, q, f);
		if (compare_weights(f->id_table[q->prev[next->id]], next, q, f) == 1
		&& f->id_table[q->prev[next->id]] != f->start
		&& check_loops(f->id_table[q->prev[next->id]], next, q, f) == 1)
		{
			switch_flows(f->id_table[q->prev[next->id]], next, q, f);
			q->prev[q->prev[next->id]] = next->id;
		}
		q->prev[next->id] = current->id;
		return (1);

}