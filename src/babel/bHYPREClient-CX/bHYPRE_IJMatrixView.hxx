// 
// File:          bHYPRE_IJMatrixView.hxx
// Symbol:        bHYPRE.IJMatrixView-v1.0.0
// Symbol Type:   interface
// Babel Version: 1.0.4
// Description:   Client-side glue code for bHYPRE.IJMatrixView
// 
// WARNING: Automatically generated; changes will be lost
// 
// 

#ifndef included_bHYPRE_IJMatrixView_hxx
#define included_bHYPRE_IJMatrixView_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
// declare class before main #includes
// (this alleviates circular #include guard problems)[BUG#393]
namespace bHYPRE { 

  class IJMatrixView;
} // end namespace bHYPRE

// Some compilers need to define array template before the specializations
namespace sidl {
  template<>
  class array< ::bHYPRE::IJMatrixView >;
}
// 
// Forward declarations for method dependencies.
// 
namespace bHYPRE { 

  class MPICommunicator;
} // end namespace bHYPRE

namespace sidl { 

  class RuntimeException;
} // end namespace sidl

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_bHYPRE_IJMatrixView_IOR_h
#include "bHYPRE_IJMatrixView_IOR.h"
#endif
#ifndef included_bHYPRE_MatrixVectorView_hxx
#include "bHYPRE_MatrixVectorView.hxx"
#endif
namespace sidl {
  namespace rmi {
    class Call;
    class Return;
    class Ticket;
  }
  namespace rmi {
    class InstanceHandle;
  }
}
namespace bHYPRE { 

  /**
   * Symbol "bHYPRE.IJMatrixView" (version 1.0.0)
   * 
   * This interface represents a linear-algebraic conceptual view of a
   * linear system.  The 'I' and 'J' in the name are meant to be
   * mnemonic for the traditional matrix notation A(I,J).
   */
  class IJMatrixView: public virtual ::bHYPRE::MatrixVectorView {

    //////////////////////////////////////////////////
    // 
    // Special methods for throwing exceptions
    // 

  private:
    static 
    void
    throwException0(
      struct sidl_BaseInterface__object *_exception
    )
      // throws:
    ;

    //////////////////////////////////////////////////
    // 
    // User Defined Methods
    // 

  public:

    /**
     * Set the local range for a matrix object.  Each process owns
     * some unique consecutive range of rows, indicated by the
     * global row indices {\tt ilower} and {\tt iupper}.  The row
     * data is required to be such that the value of {\tt ilower} on
     * any process $p$ be exactly one more than the value of {\tt
     * iupper} on process $p-1$.  Note that the first row of the
     * global matrix may start with any integer value.  In
     * particular, one may use zero- or one-based indexing.
     * 
     * For square matrices, {\tt jlower} and {\tt jupper} typically
     * should match {\tt ilower} and {\tt iupper}, respectively.
     * For rectangular matrices, {\tt jlower} and {\tt jupper}
     * should define a partitioning of the columns.  This
     * partitioning must be used for any vector $v$ that will be
     * used in matrix-vector products with the rectangular matrix.
     * The matrix data structure may use {\tt jlower} and {\tt
     * jupper} to store the diagonal blocks (rectangular in general)
     * of the matrix separately from the rest of the matrix.
     * 
     * Collective.
     */
    int32_t
    SetLocalRange (
      /* in */int32_t ilower,
      /* in */int32_t iupper,
      /* in */int32_t jlower,
      /* in */int32_t jupper
    )
    ;



    /**
     * Sets values for {\tt nrows} of the matrix.  The arrays {\tt
     * ncols} and {\tt rows} are of dimension {\tt nrows} and
     * contain the number of columns in each row and the row
     * indices, respectively.  The array {\tt cols} contains the
     * column indices for each of the {\tt rows}, and is ordered by
     * rows.  The data in the {\tt values} array corresponds
     * directly to the column entries in {\tt cols}.  The last argument
     * is the size of the cols and values arrays, i.e. the total number
     * of nonzeros being provided, i.e. the sum of all values in ncols.
     * This functin erases any previous values at the specified locations and
     * replaces them with new ones, or, if there was no value there before,
     * inserts a new one.
     * 
     * Not collective.
     */
    int32_t
    SetValues (
      /* in */int32_t nrows,
      /* in rarray[nrows] */int32_t* ncols,
      /* in rarray[nrows] */int32_t* rows,
      /* in rarray[nnonzeros] */int32_t* cols,
      /* in rarray[nnonzeros] */double* values,
      /* in */int32_t nnonzeros
    )
    ;



    /**
     * Sets values for {\tt nrows} of the matrix.  The arrays {\tt
     * ncols} and {\tt rows} are of dimension {\tt nrows} and
     * contain the number of columns in each row and the row
     * indices, respectively.  The array {\tt cols} contains the
     * column indices for each of the {\tt rows}, and is ordered by
     * rows.  The data in the {\tt values} array corresponds
     * directly to the column entries in {\tt cols}.  The last argument
     * is the size of the cols and values arrays, i.e. the total number
     * of nonzeros being provided, i.e. the sum of all values in ncols.
     * This functin erases any previous values at the specified locations and
     * replaces them with new ones, or, if there was no value there before,
     * inserts a new one.
     * 
     * Not collective.
     */
    int32_t
    SetValues (
      /* in rarray[nrows] */::sidl::array<int32_t> ncols,
      /* in rarray[nrows] */::sidl::array<int32_t> rows,
      /* in rarray[nnonzeros] */::sidl::array<int32_t> cols,
      /* in rarray[nnonzeros] */::sidl::array<double> values
    )
    ;



    /**
     * Adds to values for {\tt nrows} of the matrix.  Usage details
     * are analogous to {\tt SetValues}.  Adds to any previous
     * values at the specified locations, or, if there was no value
     * there before, inserts a new one.
     * 
     * Not collective.
     */
    int32_t
    AddToValues (
      /* in */int32_t nrows,
      /* in rarray[nrows] */int32_t* ncols,
      /* in rarray[nrows] */int32_t* rows,
      /* in rarray[nnonzeros] */int32_t* cols,
      /* in rarray[nnonzeros] */double* values,
      /* in */int32_t nnonzeros
    )
    ;



    /**
     * Adds to values for {\tt nrows} of the matrix.  Usage details
     * are analogous to {\tt SetValues}.  Adds to any previous
     * values at the specified locations, or, if there was no value
     * there before, inserts a new one.
     * 
     * Not collective.
     */
    int32_t
    AddToValues (
      /* in rarray[nrows] */::sidl::array<int32_t> ncols,
      /* in rarray[nrows] */::sidl::array<int32_t> rows,
      /* in rarray[nnonzeros] */::sidl::array<int32_t> cols,
      /* in rarray[nnonzeros] */::sidl::array<double> values
    )
    ;



    /**
     * Gets range of rows owned by this processor and range of
     * column partitioning for this processor.
     */
    int32_t
    GetLocalRange (
      /* out */int32_t& ilower,
      /* out */int32_t& iupper,
      /* out */int32_t& jlower,
      /* out */int32_t& jupper
    )
    ;



    /**
     * Gets number of nonzeros elements for {\tt nrows} rows
     * specified in {\tt rows} and returns them in {\tt ncols},
     * which needs to be allocated by the user.
     */
    int32_t
    GetRowCounts (
      /* in */int32_t nrows,
      /* in rarray[nrows] */int32_t* rows,
      /* inout rarray[nrows] */int32_t* ncols
    )
    ;



    /**
     * Gets number of nonzeros elements for {\tt nrows} rows
     * specified in {\tt rows} and returns them in {\tt ncols},
     * which needs to be allocated by the user.
     */
    int32_t
    GetRowCounts (
      /* in rarray[nrows] */::sidl::array<int32_t> rows,
      /* inout rarray[nrows] */::sidl::array<int32_t>& ncols
    )
    ;



    /**
     * Gets values for {\tt nrows} rows or partial rows of the
     * matrix.  Usage details are analogous to {\tt SetValues}.
     */
    int32_t
    GetValues (
      /* in */int32_t nrows,
      /* in rarray[nrows] */int32_t* ncols,
      /* in rarray[nrows] */int32_t* rows,
      /* in rarray[nnonzeros] */int32_t* cols,
      /* inout rarray[nnonzeros] */double* values,
      /* in */int32_t nnonzeros
    )
    ;



    /**
     * Gets values for {\tt nrows} rows or partial rows of the
     * matrix.  Usage details are analogous to {\tt SetValues}.
     */
    int32_t
    GetValues (
      /* in rarray[nrows] */::sidl::array<int32_t> ncols,
      /* in rarray[nrows] */::sidl::array<int32_t> rows,
      /* in rarray[nnonzeros] */::sidl::array<int32_t> cols,
      /* inout rarray[nnonzeros] */::sidl::array<double>& values
    )
    ;



    /**
     * (Optional) Set the max number of nonzeros to expect in each
     * row.  The array {\tt sizes} contains estimated sizes for each
     * row on this process.  The integer nrows is the number of rows in
     * the local matrix.  This call can significantly improve the
     * efficiency of matrix construction, and should always be
     * utilized if possible.
     * 
     * Not collective.
     */
    int32_t
    SetRowSizes (
      /* in rarray[nrows] */int32_t* sizes,
      /* in */int32_t nrows
    )
    ;



    /**
     * (Optional) Set the max number of nonzeros to expect in each
     * row.  The array {\tt sizes} contains estimated sizes for each
     * row on this process.  The integer nrows is the number of rows in
     * the local matrix.  This call can significantly improve the
     * efficiency of matrix construction, and should always be
     * utilized if possible.
     * 
     * Not collective.
     */
    int32_t
    SetRowSizes (
      /* in rarray[nrows] */::sidl::array<int32_t> sizes
    )
    ;



    /**
     * Print the matrix to file.  This is mainly for debugging
     * purposes.
     */
    int32_t
    Print (
      /* in */const ::std::string& filename
    )
    ;



    /**
     * Read the matrix from file.  This is mainly for debugging
     * purposes.
     */
    int32_t
    Read (
      /* in */const ::std::string& filename,
      /* in */::bHYPRE::MPICommunicator comm
    )
    ;



    //////////////////////////////////////////////////
    // 
    // End User Defined Methods
    // (everything else in this file is specific to
    //  Babel's C++ bindings)
    // 

  public:
    typedef struct bHYPRE_IJMatrixView__object ior_t;
    typedef struct bHYPRE_IJMatrixView__external ext_t;
    typedef struct bHYPRE_IJMatrixView__sepv sepv_t;

    // default constructor
    IJMatrixView() { 
      bHYPRE_IJMatrixView_IORCache = NULL;
    }

    // RMI connect
    static inline ::bHYPRE::IJMatrixView _connect( /*in*/ const std::string& 
      url ) { 
      return _connect(url, true);
    }

    // RMI connect 2
    static ::bHYPRE::IJMatrixView _connect( /*in*/ const std::string& url, 
      /*in*/ const bool ar  );

    // default destructor
    virtual ~IJMatrixView () { }

    // copy constructor
    IJMatrixView ( const IJMatrixView& original );

    // assignment operator
    IJMatrixView& operator= ( const IJMatrixView& rhs );

    // conversion from ior to C++ class
    IJMatrixView ( IJMatrixView::ior_t* ior );

    // Alternate constructor: does not call addRef()
    // (sets d_weak_reference=isWeak)
    // For internal use by Impls (fixes bug#275)
    IJMatrixView ( IJMatrixView::ior_t* ior, bool isWeak );

    inline ior_t* _get_ior() const throw() {
      if(!bHYPRE_IJMatrixView_IORCache) { 
        bHYPRE_IJMatrixView_IORCache = ::bHYPRE::IJMatrixView::_cast((
          void*)d_self);
        if (bHYPRE_IJMatrixView_IORCache) {
          struct sidl_BaseInterface__object *throwaway_exception;
          (bHYPRE_IJMatrixView_IORCache->d_epv->f_deleteRef)(
            bHYPRE_IJMatrixView_IORCache->d_object, &throwaway_exception);  
        }  
      }
      return bHYPRE_IJMatrixView_IORCache;
    }

    void _set_ior( ior_t* ptr ) throw () { 
      d_self = reinterpret_cast< void*>(ptr);
    }

    bool _is_nil() const throw () { return (d_self==0); }

    bool _not_nil() const throw () { return (d_self!=0); }

    bool operator !() const throw () { return (d_self==0); }

    static inline const char * type_name() throw () { return 
      "bHYPRE.IJMatrixView";}

    static struct bHYPRE_IJMatrixView__object* _cast(const void* src);

    // execute member function by name
    void _exec(const std::string& methodName,
               ::sidl::rmi::Call& inArgs,
               ::sidl::rmi::Return& outArgs);

    /**
     * Get the URL of the Implementation of this object (for RMI)
     */
    ::std::string
    _getURL() // throws:
    //     ::sidl::RuntimeException
    ;


    /**
     * Method to set whether or not method hooks should be invoked.
     */
    void
    _set_hooks (
      /* in */bool on
    )
    // throws:
    //     ::sidl::RuntimeException
    ;

    // return true iff object is remote
    bool _isRemote() const { 
      ior_t* self = const_cast<ior_t*>(_get_ior() );
      struct sidl_BaseInterface__object *throwaway_exception;
      return (*self->d_epv->f__isRemote)(self, &throwaway_exception) == TRUE;
    }

    // return true iff object is local
    bool _isLocal() const {
      return !_isRemote();
    }

  protected:
    // Pointer to external (DLL loadable) symbols (shared among instances)
    static const ext_t * s_ext;

  public:
    static const ext_t * _get_ext() throw ( ::sidl::NullIORException );


    //////////////////////////////////////////////////
    // 
    // Locally Cached IOR pointer
    // 

  protected:
    mutable ior_t* bHYPRE_IJMatrixView_IORCache;
  }; // end class IJMatrixView
} // end namespace bHYPRE

extern "C" {


#pragma weak bHYPRE_IJMatrixView__connectI

#pragma weak bHYPRE_IJMatrixView__rmicast

  /**
   * Cast method for interface and class type conversions.
   */
  struct bHYPRE_IJMatrixView__object*
  bHYPRE_IJMatrixView__rmicast(
    void* obj, struct sidl_BaseInterface__object **_ex);

  /**
   * RMI connector function for the class. (no addref)
   */
  struct bHYPRE_IJMatrixView__object*
  bHYPRE_IJMatrixView__connectI(const char * url, sidl_bool ar, struct 
    sidl_BaseInterface__object **_ex);


} // end extern "C"
namespace sidl {
  // traits specialization
  template<>
  struct array_traits< ::bHYPRE::IJMatrixView > {
    typedef array< ::bHYPRE::IJMatrixView > cxx_array_t;
    typedef ::bHYPRE::IJMatrixView cxx_item_t;
    typedef struct bHYPRE_IJMatrixView__array ior_array_t;
    typedef sidl_interface__array ior_array_internal_t;
    typedef struct bHYPRE_IJMatrixView__object ior_item_t;
    typedef cxx_item_t value_type;
    typedef value_type reference;
    typedef value_type* pointer;
    typedef const value_type const_reference;
    typedef const value_type* const_pointer;
    typedef array_iter< array_traits< ::bHYPRE::IJMatrixView > > iterator;
    typedef const_array_iter< array_traits< ::bHYPRE::IJMatrixView > > 
      const_iterator;
  };

  // array specialization
  template<>
  class array< ::bHYPRE::IJMatrixView >: public interface_array< array_traits< 
    ::bHYPRE::IJMatrixView > > {
  public:
    typedef interface_array< array_traits< ::bHYPRE::IJMatrixView > > Base;
    typedef array_traits< ::bHYPRE::IJMatrixView >::cxx_array_t          
      cxx_array_t;
    typedef array_traits< ::bHYPRE::IJMatrixView >::cxx_item_t           
      cxx_item_t;
    typedef array_traits< ::bHYPRE::IJMatrixView >::ior_array_t          
      ior_array_t;
    typedef array_traits< ::bHYPRE::IJMatrixView >::ior_array_internal_t 
      ior_array_internal_t;
    typedef array_traits< ::bHYPRE::IJMatrixView >::ior_item_t           
      ior_item_t;

    /**
     * conversion from ior to C++ class
     * (constructor/casting operator)
     */
    array( struct bHYPRE_IJMatrixView__array* src = 0) : Base(src) {}

    /**
     * copy constructor
     */
    array( const array< ::bHYPRE::IJMatrixView >&src) : Base(src) {}

    /**
     * assignment
     */
    array< ::bHYPRE::IJMatrixView >&
    operator =( const array< ::bHYPRE::IJMatrixView >&rhs ) { 
      if (d_array != rhs._get_baseior()) {
        if (d_array) deleteRef();
        d_array = const_cast<sidl__array *>(rhs._get_baseior());
        if (d_array) addRef();
      }
      return *this;
    }

  };
}

#ifndef included_bHYPRE_MPICommunicator_hxx
#include "bHYPRE_MPICommunicator.hxx"
#endif
#endif
