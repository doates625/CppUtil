/**
 * @file SmartPtr.h
 * @brief Embedded-compatible implementation of smart pointers.
 * 
 * Features:
 * - Dynamic memory and array flags
 * - Reference counting
 * - Automatic de-allocation of dynamic memory
 * 
 * @author Dan Oates (WPI Class of 2020)
 */
#include <stdint.h>

/** Dynamic memory flag enumeration */
typedef enum
{
	sp_is_new = 1,
	sp_not_new = 0,
}
sp_newflag_t;

/** Array flag enumeration */
typedef enum
{
	sp_is_array = 1,
	sp_not_array = 0,
}
sp_arrayflag_t;

template <class T>
class SmartPtr
{
public:

	/**
	 * @brief Constructs empty smart pointer.
	 */
	SmartPtr()
	{
		this->is_new = sp_not_new;
		this->is_array = sp_not_array;
		this->ref_count_ptr = 0;
		this->val_ptr = 0;
	}

	/**
	 * @brief Constructs smart pointer.
	 * @param ptr Pointer to memory
	 * @param is_new Dynamic memory flag
	 * @param is_array Array indicator flag
	 */
	SmartPtr(T* ptr, sp_newflag_t is_new, sp_arrayflag_t is_array)
	{
		this->is_new = is_new;
		this->is_array = is_array;
		this->ref_count_ptr = new uint32_t(0);
		this->val_ptr = ptr;
	}

	/**
	 * @brief Copy constructor.
	 */
	SmartPtr(const SmartPtr& sp)
	{
		this->is_new = sp.is_new;
		this->is_array = sp.is_array;
		this->ref_count_ptr = sp.ref_count_ptr;
		this->val_ptr = sp.val_ptr;
		(*ref_count_ptr)++;
	}

	/**
	 * @brief Dereference operator.
	 */
	T& operator*() const
	{
		return *val_ptr;
	}

	/**
	 * @brief Member dereference operator.
	 */
	T* operator->() const
	{
		return val_ptr;
	}

	/**
	 * @brief Assignment operator.
	 */
	SmartPtr& operator=(const SmartPtr& sp)
	{
		decr_ref_count();
		this->is_new = sp.is_new;
		this->is_array = sp.is_array;
		this->ref_count_ptr = sp.ref_count_ptr;
		this->val_ptr = sp.val_ptr;
		incr_ref_count();
		return (*this);
	}

	/**
	 * @brief Destructor.
	 */
	~SmartPtr()
	{
		decr_ref_count();
	}

private:

	/**
	 * @brief Increments ref counter for dynamic memory.
	 */
	void incr_ref_count()
	{
		if(is_new == sp_is_new)
		{
			(*ref_count_ptr)++;
		}
	}

	/**
	 * @brief Decrements ref counter and de-allocates dynamic memory.
	 */
	void decr_ref_count()
	{
		if(is_new == sp_is_new)
		{
			if((*ref_count_ptr) == 0)
			{
				if(is_array == sp_is_array)
				{
					delete[] val_ptr;
				}
				else
				{
					delete val_ptr;
				}
				delete ref_count_ptr;
			}
			else
			{
				(*ref_count_ptr)--;
			}
		}
	}

	/** Flag for dynamic memory */
	sp_newflag_t is_new;

	/** Flag for pointers to arrays */
	sp_arrayflag_t is_array;

	/** Pointer to reference counter */
	uint32_t* ref_count_ptr;

	/** Pointer to dynamic memory */
	T* val_ptr;
};