#include <stdio.h>

#include "core/tlibc_hash.h"
#include <string.h>

#define HASH_KEY_LENGTH 128
typedef struct _test_hash_data_t
{
	tlibc_hash_head_t hash_head;
	char key[HASH_KEY_LENGTH];
	int data;
}test_hash_data_t;

#define hash_bucket_size 1024

void test_hash()
{
	tlibc_hash_bucket_t buckets[hash_bucket_size];//定义桶的大小
	tlibc_hash_t hash_table;//定义hash表
	test_hash_data_t d0, d1, d2;
	tlibc_hash_head_t *pos;
	const tlibc_hash_head_t *pos_const;
	const test_hash_data_t *data;
	const TLIBC_LIST_HEAD *iter;
	const TLIBC_LIST_HEAD *iter_bucket;

	//准备数据
	d0.data = 0;
	snprintf(d0.key, HASH_KEY_LENGTH, "d0");

	d1.data = 10;
	snprintf(d1.key, HASH_KEY_LENGTH, "d1");

	d2.data = 200;
	snprintf(d2.key, HASH_KEY_LENGTH, "d2");

	//buckets内存不可释放掉
	tlibc_hash_init(&hash_table, buckets, hash_bucket_size);

	//insert
	//插入数据之后, key指向的内存不可以释放掉
	tlibc_hash_insert(&hash_table, d0.key, strlen(d0.key), &d0.hash_head);
	tlibc_hash_insert(&hash_table, d1.key, strlen(d1.key), &d1.hash_head);
	tlibc_hash_insert(&hash_table, d2.key, strlen(d2.key), &d2.hash_head);

	pos_const = tlibc_hash_find_const(&hash_table, "d0", 2);
	if(pos_const != NULL)
	{
		data = TLIBC_CONTAINER_OF(pos_const, const test_hash_data_t, hash_head);
		printf("find d0 data: %d\n", data->data);
	}
	

	//遍历所有数据
	printf("\n");
	for(iter_bucket = hash_table.used_bucket_list.next; iter_bucket != &hash_table.used_bucket_list; iter_bucket = iter_bucket->next)
	{
		const tlibc_hash_bucket_t *bucket = TLIBC_CONTAINER_OF(iter_bucket, const tlibc_hash_bucket_t, used_bucket_list);
		for(iter = bucket->data_list.next; iter != &bucket->data_list; iter = iter->next)
		{
			data = TLIBC_CONTAINER_OF(iter, const test_hash_data_t, hash_head);
			printf("key %s, data %d\n", data->key, data->data);
		}
	}
	
	
	//删除
	printf("\n");
	pos = tlibc_hash_find(&hash_table, "d2", 2);
	if(pos != NULL)
	{
		data = TLIBC_CONTAINER_OF(pos, const test_hash_data_t, hash_head);
		printf("find d2 data: %d\n", data->data);


		tlibc_hash_remove(&hash_table, pos);
		pos_const = tlibc_hash_find_const(&hash_table, "d2", 2);
		if(pos_const == NULL)
		{
			data = TLIBC_CONTAINER_OF(pos_const, const test_hash_data_t, hash_head);
			printf("can not find d2\n");
		}
	}

	//清空hash表
	printf("\n");
	tlibc_hash_clear(&hash_table);
	pos_const = tlibc_hash_find_const(&hash_table, "d0", 2);
	if(pos_const == NULL)
	{
		printf("can not find d0\n");
	}
}

int main()
{
	test_hash();

	return 0;
}
