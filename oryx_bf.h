/*   oryx_bf.h
 *   Created by TSIHANG <qh_soledadboy@sina.com>>
 *   12 July, 2017
 *   Personal.Q
 */
 
#ifndef __ORYX_BF_H__
#define __ORYX_BF_H__

#define MAX_HASH_FUNS	4

typedef uint32_t (*hashfunc_ptr)(char *data, unsigned int s);

struct hash {
	const char *desc;
	hashfunc_ptr func;
} ;

/**
(1-e-kn/m)k
k: hash count.
m: inserted elements.
n: map bits
*/
struct oryx_bf_t {
	
	const char *bf_desc;
	int	max;
	int k;
	void *m;	/** Bit array */
	int nelmts;	/**  */
	int n;	/** Mapping maximum objects number. */
	struct hash hash [MAX_HASH_FUNS]; 
};

#define HASH_INIT(hash, f)\
		(hash)->func=f;\
		(hash)->desc=#f

#define HASH_DESC(bf,i) ((&bf->hash[i])->desc)
#define HASH_FUNC(bf,i) ((&bf->hash[i])->func)


extern struct oryx_bf_t *bf_new (const char *bfdesc, int maxobjs);
extern int bf_add (struct oryx_bf_t *bf, void *data, size_t s);
extern int bf_query (struct oryx_bf_t *bf, void *data, size_t s);
extern void bf_dump_array (struct oryx_bf_t *bf);

#endif
