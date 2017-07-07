#pragma warning(disable: 4996)

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define ABS(x) (((x) < 0) ? -(x) : (x))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define NUM_EXAMPLES 60

typedef struct Exampe {
	float size;
	float price;
}Example;

Example *example_list;

float theta_0, theta_1;

float getLinearHypothesis(const float x) {
	return theta_0 + theta_1 * x;
}

float getMeanSquareError() {
	float error_sum = 0.0f;

	for (int e = 0; e < NUM_EXAMPLES; e++) {
		const float error = example_list[e].price - getLinearHypothesis(example_list[e].size);
		error_sum += error * error; 
	}
	return error_sum / (float)NUM_EXAMPLES * 0.5f;
}

void updateOneGDStep(const float alpha) {
	float dJ_dth0 = 0.0f, dJ_dth1 = 0.0f;
	for (int e = 0; e < NUM_EXAMPLES; e++) {
		const float h_minus_y = getLinearHypothesis(example_list[e].size) - example_list[e].price;
		const float dh_dth0 = 1.0f;
		const float dh_dth1 = example_list[e].size;

		dJ_dth0 += h_minus_y * dh_dth0;
		dJ_dth1 += h_minus_y * dh_dth1;
	}
	theta_0 -= alpha * dJ_dth0 / (float)NUM_EXAMPLES;
	theta_1 -= alpha * dJ_dth1 / (float)NUM_EXAMPLES;
}
int main() {
	example_list = (Exampe*)malloc(sizeof(Exampe)*NUM_EXAMPLES);

	FILE *ifp = fopen("d:/traintext/yeongtong.txt", "r");

	for (int i = 0; i < NUM_EXAMPLES; i++) {
		float size_input, price_input;
		fscanf(ifp, "%f %f", &size_input, &price_input);
		
		example_list[i].size = size_input;
		example_list[i].price = price_input;

		printf_s("%f %f\n", size_input, price_input);
	}
	fclose(ifp);

	float size_min = (float)1e8, size_max = - (float)1e8;
	float price_min = (float)1e8, price_max = -(float)1e8;

	for (int i = 0; i < NUM_EXAMPLES; i++) {
		size_min = MIN(size_min, example_list[i].size);
		size_max = MAX(size_max, example_list[i].size);

		price_min = MIN(size_min, example_list[i].price);
		price_max = MAX(size_max, example_list[i].price);
	}
	assert(size_max != size_min);
	assert(price_max != price_min);

	float size_scale = 1.0f / (size_max - size_min);
	float price_scale = 1.0f / (price_max - price_min);
	for (int i = 0; i < NUM_EXAMPLES; i++) {
		example_list[i].size -= size_min;
		example_list[i].size *= size_scale;
		example_list[i].price -= price_min;
		example_list[i].price *= price_scale;
	}
	theta_0 = 0.0f;
	theta_1 = 0.0f;

	float MSE_prev = 1e8;
	float th0_prev = theta_0;
	float th1_prev = theta_1;

	int i;
	for (i = 0; i < 2000; i++) {
		updateOneGDStep(0.03f);

		const float MSE = getMeanSquareError();
		const float MSE_de = MSE * (price_max - price_min) * (price_max - price_min);
		const float th0_de = (theta_0 - theta_1 * size_min * size_scale + price_min * price_scale) / price_scale;
		const float th1_de = theta_1 * size_scale / price_scale;

		printf_s("J(%.1f, %1f) = %f \n", th1_de, th0_de, MSE_de);
		if (ABS(MSE_prev) <= ABS(MSE)) {
			theta_0 = th0_prev;
			theta_1 = th1_prev;

			break;
		}
		MSE_prev = MSE;
		th0_prev = theta_0;
		th1_prev = theta_1;
	}

	printf_s("Iteration = %d \n", i);
	FILE *fp = fopen("d:/hypothesis.txt", "w");

	if (fp == NULL) {
		printf("Cannot open file for writing");
	}
	for (int size = 0; size < 140; size++) {
		const float size1 = ((float)size - size_min) * size_scale;
		const float price_fs = getLinearHypothesis(size) * (price_max - price_min) + price_min;

		fprintf(fp, "%.1f %.1f\n", (float)size1, price_fs);
	}
	fclose(fp);

	free(example_list);

	return 0;

}