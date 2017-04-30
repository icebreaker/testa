#include "testa.h"

int sample_magic_numbers(void)
{
	int a = 42;

	TESTA_ASSERT_EQUAL(a, 13);

	return 0;
}

int sample_more_magic_numbers(void)
{
	int b = 42;

	TESTA_ASSERT_EQUAL(b, 42);

	return 0;
}

int sample_that_will_be_skipped(void)
{
	TESTA_SKIP();

	TESTA_ASSERT_NOT_EQUAL(13, 13);

	return 0;
}

int sample_is_not_null(void)
{
	int *p = NULL;

	TESTA_ASSERT(p != NULL);

	return 0;
}

int sample_pointer_equality(void)
{
	int *p = NULL;

	TESTA_ASSERT_EQUAL(p, NULL);

	return 0;
}

int sample_swap_numbers(void)
{
	int a = 13, b = 14, tmp;

	tmp = a;
	a = b;
	b = a;

	TESTA_ASSERT_EQUAL(tmp, 13);
	TESTA_ASSERT_EQUAL(a, 14);
	TESTA_ASSERT_EQUAL(b, 13);

	return 0;
}

TESTA_SUITE_BEGIN
	TESTA_GROUP_BEGIN("sample test group");
		TESTA_TEST(sample_magic_numbers);
		TESTA_TEST(sample_more_magic_numbers);
		TESTA_TEST(sample_that_will_be_skipped);
		TESTA_TEST(sample_is_not_null);
		TESTA_GROUP_BEGIN("sample sub test group");
			TESTA_TEST(sample_pointer_equality);
			TESTA_TEST(sample_swap_numbers);
		TESTA_GROUP_END
	TESTA_GROUP_END
TESTA_SUITE_END
