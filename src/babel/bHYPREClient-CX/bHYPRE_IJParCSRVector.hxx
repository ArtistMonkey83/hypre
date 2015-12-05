// 
// File:          bHYPRE_IJParCSRVector.hxx
// Symbol:        bHYPRE.IJParCSRVector-v1.0.0
// Symbol Type:   class
// Babel Version: 1.0.4
// Description:   Client-side glue code for bHYPRE.IJParCSRVector
// 
// WARNING: Automatically generated; changes will be lost
// 
// 

#ifndef included_bHYPRE_IJParCSRVector_hxx
#define included_bHYPRE_IJParCSRVector_hxx

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
// declare class before main #includes
// (this alleviates circular #include guard problems)[BUG#393]
namespace bHYPRE { 

  class IJParCSRVector;
} // end namespace bHYPRE

// Some compilers need to define array template before the specializations
namespace sidl {
  template<>
  class array< ::bHYPRE::IJParCSRVector >;
}
// 
// Forward declarations for method dependencies.
// 
namespace bHYPRE { 

  class IJParCSRVector;
} // end namespace bHYPRE

namespace bHYPRE { 

  class MPICommunicator;
} // end namespace bHYPRE

namespace bHYPRE { 

  class Vector;
} // end namespace bHYPRE

namespace sidl { 

  class RuntimeException;
} // end namespace sidl

#ifndef included_sidl_cxx_hxx
#include "sidl_cxx.hxx"
#endif
#ifndef included_bHYPRE_IJParCSRVector_IOR_h
#include "bHYPRE_IJParCSRVector_IOR.h"
#endif
#ifndef included_bHYPRE_IJVectorView_hxx
#include "bHYPRE_IJVectorView.hxx"
#endif
#ifndef included_bHYPRE_Vector_hxx
#include "bHYPRE_Vector.hxx"
#endif
#ifndef included_sidl_BaseClass_hxx
#include "sidl_BaseClass.hxx"
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
   * Symbol "bHYPRE.IJParCSRVector" (version 1.0.0)
   * 
   * The IJParCSR vector class.
   * 
   * Objects of this type can be cast to IJVectorView or Vector
   * objects using the {\tt \_\_cast} methods.
   */
  class IJParCSRVector: public virtual ::bHYPRE::IJVectorView, public virtual 
    ::bHYPRE::Vector, public virtual ::sidl::BaseClass {

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
     *  This function is the preferred way to create an IJParCSR Vector. 
     */
    static ::bHYPRE::IJParCSRVector
    Create (
      /* in */::bHYPRE::MPICommunicator mpi_comm,
      /* in */int32_t jlower,
      /* in */int32_t jupper
    )
    ;



    /**
     * Set the local range for a vector object.  Each process owns
     * some unique consecutive range of vector unknowns, indicated
     * by the global indices {\tt jlower} and {\tt jupper}.  The
     * data is required to be such that the value of {\tt jlower} on
     * any process $p$ be exactly one more than the value of {\tt
     * jupper} on process $p-1$.  Note that the first index of the
     * global vector may start with any integer value.  In
     * particular, one may use zero- or one-based indexing.
     * 
     * Collective.
     */
    int32_t
    SetLocalRange (
      /* in */int32_t jlower,
      /* in */int32_t jupper
    )
    ;



    /**
     * Sets values in vector.  The arrays {\tt values} and {\tt
     * indices} are of dimension {\tt nvalues} and contain the
     * vector values to be set and the corresponding global vector
     * indices, respectively.  Erases any previous values at the
     * specified locations and replaces them with new ones.
     * 
     * Not collective.
     */
    int32_t
    SetValues (
      /* in */int32_t nvalues,
      /* in rarray[nvalues] */int32_t* indices,
      /* in rarray[nvalues] */double* values
    )
    ;



    /**
     * Sets values in vector.  The arrays {\tt values} and {\tt
     * indices} are of dimension {\tt nvalues} and contain the
     * vector values to be set and the corresponding global vector
     * indices, respectively.  Erases any previous values at the
     * specified locations and replaces them with new ones.
     * 
     * Not collective.
     */
    int32_t
    SetValues (
      /* in rarray[nvalues] */::sidl::array<int32_t> indices,
      /* in rarray[nvalues] */::sidl::array<double> values
    )
    ;



    /**
     * Adds to values in vector.  Usage details are analogous to
     * {\tt SetValues}.
     * 
     * Not collective.
     */
    int32_t
    AddToValues (
      /* in */int32_t nvalues,
      /* in rarray[nvalues] */int32_t* indices,
      /* in rarray[nvalues] */double* values
    )
    ;



    /**
     * Adds to values in vector.  Usage details are analogous to
     * {\tt SetValues}.
     * 
     * Not collective.
     */
    int32_t
    AddToValues (
      /* in rarray[nvalues] */::sidl::array<int32_t> indices,
      /* in rarray[nvalues] */::sidl::array<double> values
    )
    ;



    /**
     * Returns range of the part of the vector owned by this
     * processor.
     */
    int32_t
    GetLocalRange (
      /* out */int32_t& jlower,
      /* out */int32_t& jupper
    )
    ;



    /**
     * Gets values in vector.  Usage details are analogous to {\tt
     * SetValues}.
     * 
     * Not collective.
     */
    int32_t
    GetValues (
      /* in */int32_t nvalues,
      /* in rarray[nvalues] */int32_t* indices,
      /* inout rarray[nvalues] */double* values
    )
    ;



    /**
     * Gets values in vector.  Usage details are analogous to {\tt
     * SetValues}.
     * 
     * Not collective.
     */
    int32_t
    GetValues (
      /* in rarray[nvalues] */::sidl::array<int32_t> indices,
      /* inout rarray[nvalues] */::sidl::array<double>& values
    )
    ;



    /**
     * Print the vector to file.  This is mainly for debugging
     * purposes.
     */
    int32_t
    Print (
      /* in */const ::std::string& filename
    )
    ;



    /**
     * Read the vector from file.  This is mainly for debugging
     * purposes.
     */
    int32_t
    Read (
      /* in */const ::std::string& filename,
      /* in */::bHYPRE::MPICommunicator comm
    )
    ;



    /**
     * Set the MPI Communicator.  DEPRECATED, Use Create()
     */
    int32_t
    SetCommunicator (
      /* in */::bHYPRE::MPICommunicator mpi_comm
    )
    ;



    /**
     * The Destroy function doesn't necessarily destroy anything.
     * It is just another name for deleteRef.  Thus it decrements the
     * object's reference count.  The Babel memory management system will
     * destroy the object if the reference count goes to zero.
     */
    void
    Destroy() ;


    /**
     * Prepare an object for setting coefficient values, whether for
     * the first time or subsequently.
     */
    int32_t
    Initialize() ;


    /**
     * Finalize the construction of an object before using, either
     * for the first time or on subsequent uses. {\tt Initialize}
     * and {\tt Assemble} always appear in a matched set, with
     * Initialize preceding Assemble. Values can only be set in
     * between a call to Initialize and Assemble.
     */
    int32_t
    Assemble() ;


    /**
     * Set {\tt self} to 0.
     */
    int32_t
    Clear() ;


    /**
     * Copy data from x into {\tt self}.
     */
    int32_t
    Copy (
      /* in */::bHYPRE::Vector x
    )
    ;



    /**
     * Create an {\tt x} compatible with {\tt self}.
     * The new vector's data is not specified.
     * 
     * NOTE: When this method is used in an inherited class, the
     * cloned {\tt Vector} object can be cast to an object with the
     * inherited class type.
     */
    int32_t
    Clone (
      /* out */::bHYPRE::Vector& x
    )
    ;



    /**
     * Scale {\tt self} by {\tt a}.
     */
    int32_t
    Scale (
      /* in */double a
    )
    ;



    /**
     * Compute {\tt d}, the inner-product of {\tt self} and {\tt x}.
     */
    int32_t
    Dot (
      /* in */::bHYPRE::Vector x,
      /* out */double& d
    )
    ;



    /**
     * Add {\tt a}{\tt x} to {\tt self}.
     */
    int32_t
    Axpy (
      /* in */double a,
      /* in */::bHYPRE::Vector x
    )
    ;



    //////////////////////////////////////////////////
    // 
    // End User Defined Methods
    // (everything else in this file is specific to
    //  Babel's C++ bindings)
    // 

  public:
    typedef struct bHYPRE_IJParCSRVector__object ior_t;
    typedef struct bHYPRE_IJParCSRVector__external ext_t;
    typedef struct bHYPRE_IJParCSRVector__sepv sepv_t;

    // default constructor
    IJParCSRVector() { 
    }

    // static constructor
    static ::bHYPRE::IJParCSRVector _create();

    // RMI constructor
    static ::bHYPRE::IJParCSRVector _create( /*in*/ const std::string& url );

    // RMI connect
    static inline ::bHYPRE::IJParCSRVector _connect( /*in*/ const std::string& 
      url ) { 
      return _connect(url, true);
    }

    // RMI connect 2
    static ::bHYPRE::IJParCSRVector _connect( /*in*/ const std::string& url, 
      /*in*/ const bool ar  );

    // default destructor
    virtual ~IJParCSRVector () { }

    // copy constructor
    IJParCSRVector ( const IJParCSRVector& original );

    // assignment operator
    IJParCSRVector& operator= ( const IJParCSRVector& rhs );


    protected:
    // Internal data wrapping method
    static ior_t*  _wrapObj(void* private_data);


    public:
    // conversion from ior to C++ class
    IJParCSRVector ( IJParCSRVector::ior_t* ior );

    // Alternate constructor: does not call addRef()
    // (sets d_weak_reference=isWeak)
    // For internal use by Impls (fixes bug#275)
    IJParCSRVector ( IJParCSRVector::ior_t* ior, bool isWeak );

    inline ior_t* _get_ior() const throw() {
      return reinterpret_cast< ior_t*>(d_self);
    }

    void _set_ior( ior_t* ptr ) throw () { 
      d_self = reinterpret_cast< void*>(ptr);
    }

    bool _is_nil() const throw () { return (d_self==0); }

    bool _not_nil() const throw () { return (d_self!=0); }

    bool operator !() const throw () { return (d_self==0); }

    static inline const char * type_name() throw () { return 
      "bHYPRE.IJParCSRVector";}

    static struct bHYPRE_IJParCSRVector__object* _cast(const void* src);

    // execute member function by name
    void _exec(const std::string& methodName,
               ::sidl::rmi::Call& inArgs,
               ::sidl::rmi::Return& outArgs);
    // exec static member function by name
    static void _sexec(const std::string& methodName,
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


    /**
     * Static Method to set whether or not method hooks should be invoked.
     */
    static void
    _set_hooks_static (
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

    static const sepv_t * _get_sepv() {
      return (*(_get_ext()->getStaticEPV))();
    }

  }; // end class IJParCSRVector
} // end namespace bHYPRE

extern "C" {


#pragma weak bHYPRE_IJParCSRVector__connectI

#pragma weak bHYPRE_IJParCSRVector__rmicast

  /**
   * Cast method for interface and class type conversions.
   */
  struct bHYPRE_IJParCSRVector__object*
  bHYPRE_IJParCSRVector__rmicast(
    void* obj, struct sidl_BaseInterface__object **_ex);

  /**
   * RMI connector function for the class. (no addref)
   */
  struct bHYPRE_IJParCSRVector__object*
  bHYPRE_IJParCSRVector__connectI(const char * url, sidl_bool ar, struct 
    sidl_BaseInterface__object **_ex);


} // end extern "C"
namespace sidl {
  // traits specialization
  template<>
  struct array_traits< ::bHYPRE::IJParCSRVector > {
    typedef array< ::bHYPRE::IJParCSRVector > cxx_array_t;
    typedef ::bHYPRE::IJParCSRVector cxx_item_t;
    typedef struct bHYPRE_IJParCSRVector__array ior_array_t;
    typedef sidl_interface__array ior_array_internal_t;
    typedef struct bHYPRE_IJParCSRVector__object ior_item_t;
    typedef cxx_item_t value_type;
    typedef value_type reference;
    typedef value_type* pointer;
    typedef const value_type const_reference;
    typedef const value_type* const_pointer;
    typedef array_iter< array_traits< ::bHYPRE::IJParCSRVector > > iterator;
    typedef const_array_iter< array_traits< ::bHYPRE::IJParCSRVector > > 
      const_iterator;
  };

  // array specialization
  template<>
  class array< ::bHYPRE::IJParCSRVector >: public interface_array< 
    array_traits< ::bHYPRE::IJParCSRVector > > {
  public:
    typedef interface_array< array_traits< ::bHYPRE::IJParCSRVector > > Base;
    typedef array_traits< ::bHYPRE::IJParCSRVector >::cxx_array_t          
      cxx_array_t;
    typedef array_traits< ::bHYPRE::IJParCSRVector >::cxx_item_t           
      cxx_item_t;
    typedef array_traits< ::bHYPRE::IJParCSRVector >::ior_array_t          
      ior_array_t;
    typedef array_traits< ::bHYPRE::IJParCSRVector >::ior_array_internal_t 
      ior_array_internal_t;
    typedef array_traits< ::bHYPRE::IJParCSRVector >::ior_item_t           
      ior_item_t;

    /**
     * conversion from ior to C++ class
     * (constructor/casting operator)
     */
    array( struct bHYPRE_IJParCSRVector__array* src = 0) : Base(src) {}

    /**
     * copy constructor
     */
    array( const array< ::bHYPRE::IJParCSRVector >&src) : Base(src) {}

    /**
     * assignment
     */
    array< ::bHYPRE::IJParCSRVector >&
    operator =( const array< ::bHYPRE::IJParCSRVector >&rhs ) { 
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
