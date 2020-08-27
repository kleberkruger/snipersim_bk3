#ifndef CACHE_SET_KRUGER_H
#define CACHE_SET_KRUGER_H

#include "cache_set.h"
#include "cache_set_lru.h"

class CacheSetKruger : public CacheSet
{
public:
   CacheSetKruger(CacheBase::cache_t cache_type, UInt32 associativity, UInt32 blocksize,
                  CacheSetInfoLRU *set_info, UInt8 num_attempts, float percentage_to_wb = DEFAULT_WB_THRESHOLD);
   virtual ~CacheSetKruger();

   virtual UInt32 getReplacementIndex(CacheCntlr *cntlr);
   void updateReplacementIndex(UInt32 accessed_index);

protected:
   static const constexpr char *const states[] = {"I", "S", "u", "E", "O", "M"};
   static const constexpr float DEFAULT_WB_THRESHOLD = 0.75;

   UInt8 *m_lru_bits;
   CacheSetInfoLRU *m_set_info;
   const UInt8 m_num_attempts;
   float m_percentage_to_wb;

   void moveToMRU(UInt32 accessed_index);
   bool isValidReplacement(UInt32 index);
   void printBlockStats(); // FIXME: Delete-me. Apenas para debug.
};

#endif /* CACHE_SET_KRUGER_H */