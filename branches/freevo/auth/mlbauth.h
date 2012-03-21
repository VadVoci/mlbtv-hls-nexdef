#ifndef MLB_AUTH_H
#define MLB_AUTH_H

#include <stdint.h>
#include <pthread.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_STR_LEN			4096

#define SLEEP_1S			usleep(1000000);
#define SLEEP_250MS			usleep(250000);
#define SLEEP_500MS			usleep(500000);

struct mlb_curl_mem
{
	uint8_t throw_away;
	size_t size;
	char *data;
};
typedef struct mlb_curl_mem MLB_CURL_MEM;

struct mlb_auth_struct
{
	char ipid[MAX_STR_LEN];
	char fprt[MAX_STR_LEN];
	char ftmu[MAX_STR_LEN];
	time_t ipid_expire;
	time_t fprt_expire;
	time_t ftmu_expire;
	time_t current_time;
	MLB_CURL_MEM carg;
};
typedef struct mlb_auth_struct MLB_AUTH_STRUCT;

struct mlb_inning_struct
{
	uint8_t inning;
	char top_start_time[10];
	char bottom_start_time[10];
};
typedef struct mlb_inning_struct MLB_INNING_STRUCT;

struct mlb_innings_struct
{
	char start_time[10];
	MLB_INNING_STRUCT innings[50];
};
typedef struct mlb_innings_struct MLB_INNINGS_STRUCT;

#endif
