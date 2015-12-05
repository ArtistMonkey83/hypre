// 
// File:          bHYPRE_SStructVectorView.hxx
// Symbol:        bHYPRE.SStructVectorView-v1.0.0
// Symbol Type:   interface
// Babel Version: 1.0.4
// Description:   Client-side glue code for bHYPRE.SStructVectorView
// 
// WARNING: Automatically generated; changes will be lost
// 
// 

#ifndef included_bHYPRE_SStructVectorView_hxx
#define included_bHYPRE_SStructVectorView_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
// declare class before main #includes
// (this alleviates circular #include guard problems)[BUG#393]
namespace bHYPRE { 

  class SStructVectorView;
} // end namespace bHYPRE

// Some compilers need to define array template before the specializations
namespace sidl {
  template<>
  class array< ::bHYPRE::SStructVectorView >;
}
// 
// Forward declarations for method dependencies.
// 
namespace bHYPRE { 

  class SStructGrid;
} // end namespace bHYPRE

namespace sidl { 

  class RuntimeException;
} // end namespace sidl

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_bHYPRE_SStructVectorView_IOR_h
#include "bHYPRE_SStructVectorView_IOR.h"
#endif
#ifndef included_bHYPRE_SStructMatrixVectorView_hxx
#include "bHYPRE_SStructMatrixVectorView.hxx"
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
   * Symbol "bHYPRE.SStructVectorView" (version 1.0.0)
   */
  class SStructVectorView: public virtual ::bHYPRE::SStructMatrixVectorView {

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
     * Set the vector grid.
     */
    int32_t
    SetGrid (
      /* in */::bHYPRE::SStructGrid grid
    )
    ;



    /**
     * Set vector coefficients index by index.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt value} consists of a pair
     * of doubles representing the real and imaginary parts of the
     * complex value.
     */
    int32_t
    SetValues (
      /* in */int32_t part,
      /* in rarray[dim] */int32_t* index,
      /* in */int32_t dim,
      /* in */int32_t var,
      /* in */double value
    )
    ;



    /**
     * Set vector coefficients index by index.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt value} consists of a pair
     * of doubles representing the real and imaginary parts of the
     * complex value.
     */
    int32_t
    SetValues (
      /* in */int32_t part,
      /* in rarray[dim] */::sidl::array<int32_t> index,
      /* in */int32_t var,
      /* in */double value
    )
    ;



    /**
     * Set vector coefficients a box at a time.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt values} consists of pairs
     * of doubles representing the real and imaginary parts of each
     * complex value.
     */
    int32_t
    SetBoxValues (
      /* in */int32_t part,
      /* in rarray[dim] */int32_t* ilower,
      /* in rarray[dim] */int32_t* iupper,
      /* in */int32_t dim,
      /* in */int32_t var,
      /* in rarray[nvalues] */double* values,
      /* in */int32_t nvalues
    )
    ;



    /**
     * Set vector coefficients a box at a time.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt values} consists of pairs
     * of doubles representing the real and imaginary parts of each
     * complex value.
     */
    int32_t
    SetBoxValues (
      /* in */int32_t part,
      /* in rarray[dim] */::sidl::array<int32_t> ilower,
      /* in rarray[dim] */::sidl::array<int32_t> iupper,
      /* in */int32_t var,
      /* in rarray[nvalues] */::sidl::array<double> values
    )
    ;



    /**
     * Set vector coefficients index by index.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt value} consists of a pair
     * of doubles representing the real and imaginary parts of the
     * complex value.
     */
    int32_t
    AddToValues (
      /* in */int32_t part,
      /* in rarray[dim] */int32_t* index,
      /* in */int32_t dim,
      /* in */int32_t var,
      /* in */double value
    )
    ;



    /**
     * Set vector coefficients index by index.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt value} consists of a pair
     * of doubles representing the real and imaginary parts of the
     * complex value.
     */
    int32_t
    AddToValues (
      /* in */int32_t part,
      /* in rarray[dim] */::sidl::array<int32_t> index,
      /* in */int32_t var,
      /* in */double value
    )
    ;



    /**
     * Set vector coefficients a box at a time.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt values} consists of pairs
     * of doubles representing the real and imaginary parts of each
     * complex value.
     */
    int32_t
    AddToBoxValues (
      /* in */int32_t part,
      /* in rarray[dim] */int32_t* ilower,
      /* in rarray[dim] */int32_t* iupper,
      /* in */int32_t dim,
      /* in */int32_t var,
      /* in rarray[nvalues] */double* values,
      /* in */int32_t nvalues
    )
    ;



    /**
     * Set vector coefficients a box at a time.
     * 
     * NOTE: Users are required to set values on all processes that
     * own the associated variables.  This means that some data will
     * be multiply defined.
     * 
     * If the vector is complex, then {\tt values} consists of pairs
     * of doubles representing the real and imaginary parts of each
     * complex value.
     */
    int32_t
    AddToBoxValues (
      /* in */int32_t part,
      /* in rarray[dim] */::sidl::array<int32_t> ilower,
      /* in rarray[dim] */::sidl::array<int32_t> iupper,
      /* in */int32_t var,
      /* in rarray[nvalues] */::sidl::array<double> values
    )
    ;



    /**
     * Gather vector data before calling {\tt GetValues}.
     */
    int32_t
    Gather() ;


    /**
     * Get vector coefficients index by index.
     * 
     * NOTE: Users may only get values on processes that own the
     * associated variables.
     * 
     * If the vector is complex, then {\tt value} consists of a pair
     * of doubles representing the real and imaginary parts of the
     * complex value.
     */
    int32_t
    GetValues (
      /* in */int32_t part,
      /* in rarray[dim] */int32_t* index,
      /* in */int32_t dim,
      /* in */int32_t var,
      /* out */double& value
    )
    ;



    /**
     * Get vector coefficients index by index.
     * 
     * NOTE: Users may only get values on processes that own the
     * associated variables.
     * 
     * If the vector is complex, then {\tt value} consists of a pair
     * of doubles representing the real and imaginary parts of the
     * complex value.
     */
    int32_t
    GetValues (
      /* in */int32_t part,
      /* in rarray[dim] */::sidl::array<int32_t> index,
      /* in */int32_t var,
      /* out */double& value
    )
    ;



    /**
     * Get vector coefficients a box at a time.
     * 
     * NOTE: Users may only get values on processes that own the
     * associated variables.
     * 
     * If the vector is complex, then {\tt values} consists of pairs
     * of doubles representing the real and imaginary parts of each
     * complex value.
     */
    int32_t
    GetBoxValues (
      /* in */int32_t part,
      /* in rarray[dim] */int32_t* ilower,
      /* in rarray[dim] */int32_t* iupper,
      /* in */int32_t dim,
      /* in */int32_t var,
      /* inout rarray[nvalues] */double* values,
      /* in */int32_t nvalues
    )
    ;



    /**
     * Get vector coefficients a box at a time.
     * 
     * NOTE: Users may only get values on processes that own the
     * associated variables.
     * 
     * If the vector is complex, then {\tt values} consists of pairs
     * of doubles representing the real and imaginary parts of each
     * complex value.
     */
    int32_t
    GetBoxValues (
      /* in */int32_t part,
      /* in rarray[dim] */::sidl::array<int32_t> ilower,
      /* in rarray[dim] */::sidl::array<int32_t> iupper,
      /* in */int32_t var,
      /* inout rarray[nvalues] */::sidl::array<double>& values
    )
    ;



    /**
     * Set the vector to be complex.
     */
    int32_t
    SetComplex() ;


    /**
     * Print the vector to file.  This is mainly for debugging
     * purposes.
     */
    int32_t
    Print (
      /* in */const ::std::string& filename,
      /* in */int32_t all
    )
    ;



    //////////////////////////////////////////////////
    // 
    // End User Defined Methods
    // (everything else in this file is specific to
    //  Babel's C++ bindings)
    // 

  public:
    typedef struct bHYPRE_SStructVectorView__object ior_t;
    typedef struct bHYPRE_SStructVectorView__external ext_t;
    typedef struct bHYPRE_SStructVectorView__sepv sepv_t;

    // default constructor
    SStructVectorView() { 
      bHYPRE_SStructVectorView_IORCache = NULL;
    }

    // RMI connect
    static inline ::bHYPRE::SStructVectorView _connect( /*in*/ const 
      std::string& url ) { 
      return _connect(url, true);
    }

    // RMI connect 2
    static ::bHYPRE::SStructVectorView _connect( /*in*/ const std::string& url, 
      /*in*/ const bool ar  );

    // default destructor
    virtual ~SStructVectorView () { }

    // copy constructor
    SStructVectorView ( const SStructVectorView& original );

    // assignment operator
    SStructVectorView& operator= ( const SStructVectorView& rhs );

    // conversion from ior to C++ class
    SStructVectorView ( SStructVectorView::ior_t* ior );

    // Alternate constructor: does not call addRef()
    // (sets d_weak_reference=isWeak)
    // For internal use by Impls (fixes bug#275)
    SStructVectorView ( SStructVectorView::ior_t* ior, bool isWeak );

    inline ior_t* _get_ior() const throw() {
      if(!bHYPRE_SStructVectorView_IORCache) { 
        bHYPRE_SStructVectorView_IORCache = ::bHYPRE::SStructVectorView::_cast((
          void*)d_self);
        if (bHYPRE_SStructVectorView_IORCache) {
          struct sidl_BaseInterface__object *throwaway_exception;
          (bHYPRE_SStructVectorView_IORCache->d_epv->f_deleteRef)(
            bHYPRE_SStructVectorView_IORCache->d_object, &throwaway_exception); 
            
        }  
      }
      return bHYPRE_SStructVectorView_IORCache;
    }

    void _set_ior( ior_t* ptr ) throw () { 
      d_self = reinterpret_cast< void*>(ptr);
    }

    bool _is_nil() const throw () { return (d_self==0); }

    bool _not_nil() const throw () { return (d_self!=0); }

    bool operator !() const throw () { return (d_self==0); }

    static inline const char * type_name() throw () { return 
      "bHYPRE.SStructVectorView";}

    static struct bHYPRE_SStructVectorView__object* _cast(const void* src);

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
    mutable ior_t* bHYPRE_SStructVectorView_IORCache;
  }; // end class SStructVectorView
} // end namespace bHYPRE

extern "C" {


#pragma weak bHYPRE_SStructVectorView__connectI

#pragma weak bHYPRE_SStructVectorView__rmicast

  /**
   * Cast method for interface and class type conversions.
   */
  struct bHYPRE_SStructVectorView__object*
  bHYPRE_SStructVectorView__rmicast(
    void* obj, struct sidl_BaseInterface__object **_ex);

  /**
   * RMI connector function for the class. (no addref)
   */
  struct bHYPRE_SStructVectorView__object*
  bHYPRE_SStructVectorView__connectI(const char * url, sidl_bool ar, struct 
    sidl_BaseInterface__object **_ex);


} // end extern "C"
namespace sidl {
  // traits specialization
  template<>
  struct array_traits< ::bHYPRE::SStructVectorView > {
    typedef array< ::bHYPRE::SStructVectorView > cxx_array_t;
    typedef ::bHYPRE::SStructVectorView cxx_item_t;
    typedef struct bHYPRE_SStructVectorView__array ior_array_t;
    typedef sidl_interface__array ior_array_internal_t;
    typedef struct bHYPRE_SStructVectorView__object ior_item_t;
    typedef cxx_item_t value_type;
    typedef value_type reference;
    typedef value_type* pointer;
    typedef const value_type const_reference;
    typedef const value_type* const_pointer;
    typedef array_iter< array_traits< ::bHYPRE::SStructVectorView > > iterator;
    typedef const_array_iter< array_traits< ::bHYPRE::SStructVectorView > > 
      const_iterator;
  };

  // array specialization
  template<>
  class array< ::bHYPRE::SStructVectorView >: public interface_array< 
    array_traits< ::bHYPRE::SStructVectorView > > {
  public:
    typedef interface_array< array_traits< ::bHYPRE::SStructVectorView > > Base;
    typedef array_traits< ::bHYPRE::SStructVectorView >::cxx_array_t          
      cxx_array_t;
    typedef array_traits< ::bHYPRE::SStructVectorView >::cxx_item_t           
      cxx_item_t;
    typedef array_traits< ::bHYPRE::SStructVectorView >::ior_array_t          
      ior_array_t;
    typedef array_traits< ::bHYPRE::SStructVectorView >::ior_array_internal_t 
      ior_array_internal_t;
    typedef array_traits< ::bHYPRE::SStructVectorView >::ior_item_t           
      ior_item_t;

    /**
     * conversion from ior to C++ class
     * (constructor/casting operator)
     */
    array( struct bHYPRE_SStructVectorView__array* src = 0) : Base(src) {}

    /**
     * copy constructor
     */
    array( const array< ::bHYPRE::SStructVectorView >&src) : Base(src) {}

    /**
     * assignment
     */
    array< ::bHYPRE::SStructVectorView >&
    operator =( const array< ::bHYPRE::SStructVectorView >&rhs ) { 
      if (d_array != rhs._get_baseior()) {
        if (d_array) deleteRef();
        d_array = const_cast<sidl__array *>(rhs._get_baseior());
        if (d_array) addRef();
      }
      return *this;
    }

  };
}

#ifndef included_bHYPRE_SStructGrid_hxx
#include "bHYPRE_SStructGrid.hxx"
#endif
#endif
