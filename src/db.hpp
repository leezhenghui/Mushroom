/**
 *    > Author:            UncP
 *    > Mail:         770778010@qq.com
 *    > Github:    https://www.github.com/UncP/Mushroom
 *    > Created Time:  2016-10-10 15:32:20
**/

#ifndef _MUSHROOM_DB_HPP_
#define _MUSHROOM_DB_HPP_

#include <vector>

#include "btree.hpp"

namespace Mushroom {

class MushroomDB
{
	public:
		MushroomDB(const char *name, const int key_len);

		bool Put(KeySlice *key);

		bool Get(KeySlice *key);

		void IndexSingle(const char *file, const int total);

		void IndexMultipleThread(const std::vector<std::string> &files, const int total);

		void IndexMultipleProcess(const std::vector<std::string> &files, const int total);

		bool FindSingle(const char *file, const int total);

		bool FindMultiple(const std::vector<std::string> &files, const int total);

		bool Close();

		MushroomDB(const MushroomDB &) = delete;
		MushroomDB(const MushroomDB &&) = delete;
		MushroomDB& operator=(const MushroomDB &) = delete;
		MushroomDB& operator=(const MushroomDB &&) = delete;

		const BTree* Btree() const { return btree_; }

		~MushroomDB() { delete btree_; }

	private:
		int    fd_;
		char  *mapped_;
		BTree *btree_;
};

} // namespace Mushroom

#endif /* _MUSHROOM_DB_HPP_ */