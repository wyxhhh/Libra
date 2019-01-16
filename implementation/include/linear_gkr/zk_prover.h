#ifndef __zk_prover
#define __zk_prover

#include "linear_gkr/circuit_fast_track.h"
#include "linear_gkr/prime_field.h"
#include "linear_gkr/polynomial.h"
#include <cstring>
#include <utility>
#include <chrono>
class zk_prover
{
public:
	prime_field::field_element v_u, v_v;
	int total_uv;
	layered_circuit C;
	prime_field::field_element* circuit_value[1000000];

	int sumcheck_layer_id, length_g, length_u, length_v;
	prime_field::field_element alpha, beta;
	const prime_field::field_element *r_0, *r_1;
	prime_field::field_element *one_minus_r_0, *one_minus_r_1;

	linear_poly *addV_array;
	linear_poly *V_mult_add;
	prime_field::field_element *beta_u;
	prime_field::field_element *beta_g_r0_fhalf, *beta_g_r0_shalf, *beta_g_r1_fhalf, *beta_g_r1_shalf, *beta_u_fhalf, *beta_u_shalf;
	prime_field::field_element *beta_g_sum;
	linear_poly *add_mult_sum;
	int *addV_array_counter, *add_mult_sum_counter;
	double total_time;
	void init_array(int);
	void get_circuit(const layered_circuit &from_verifier);
	prime_field::field_element* evaluate();
	void proof_init();
	
	void sumcheck_init(int layer_id, int bit_length_g, int bit_length_u, int bit_length_v, const prime_field::field_element &,
		const prime_field::field_element &, const prime_field::field_element*, const prime_field::field_element*, prime_field::field_element*, prime_field::field_element*);
	void sumcheck_phase1_init();
	void sumcheck_phase2_init(prime_field::field_element, const prime_field::field_element*, const prime_field::field_element*);
	quadratic_poly sumcheck_phase1_update(prime_field::field_element, int);
	quintuple_poly sumcheck_phase1_updatelastbit(prime_field::field_element, int);
	quadratic_poly sumcheck_phase2_update(prime_field::field_element, int);
	quintuple_poly sumcheck_phase2_updatelastbit(prime_field::field_element, int);

	quadratic_poly sumcheck_finalround(prime_field::field_element, int, prime_field::field_element);
	prime_field::field_element V_res(const prime_field::field_element*, const prime_field::field_element*, const prime_field::field_element*, int, int);
	std::pair<prime_field::field_element, prime_field::field_element> sumcheck_finalize(prime_field::field_element);
	void delete_self();
	zk_prover()
	{
		memset(circuit_value, 0, sizeof circuit_value);
	}
	~zk_prover();


	//new zk function 


	prime_field::field_element *maskpoly; 
	prime_field::field_element maskpoly_sumc;
	prime_field::field_element maskpoly_sumr;
	void generate_maskpoly(int, int);

	prime_field::field_element query(prime_field::field_element*, prime_field::field_element*, prime_field::field_element);
	prime_field::field_element queryRg1(prime_field::field_element);
	prime_field::field_element queryRg2(prime_field::field_element);

	prime_field::field_element premaskR[9], maskR[9];
	prime_field::field_element maskR_sumcu, maskR_sumcv, preZu, preZv, Zu, Zv, preu1, prev1, ZuR, ZvR, Iuv;
	quadratic_poly summaskR, Rg1, Rg2, sumRc;
	void generate_maskR(int);

	//prime_field::field_element preZu, preZv, Zu, Zv, preu1, prev1, ZuR, ZvR, Iuv;

	void sumcheck_maskpoly_init();
	//prime_field::field_element *maskpoly_partialsum;
	//prime_field::field_element inv_2 = from_string("8399054365507916142470402071115866954879789801702376374514189432082785107975");

};

#endif