using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckLibrary : MonoBehaviour
{
    static VectorLibrary vectorLibrary;
    Vector3 A = new Vector3(2, 2, 2);
    Vector3 B = new Vector3(2, 2, 2);
    // Start is called before the first frame update
    void Start()
    {
        vectorLibrary = gameObject.AddComponent<VectorLibrary>();
        Debug.Log(vectorLibrary.AddTwoVectors(A, B));
        Debug.Log(vectorLibrary.SubtractTwoVectors(A, B));
        Debug.Log(vectorLibrary.VectorDotProduct(A, B));
        Debug.Log(vectorLibrary.VectorMagnitude(A));
        Debug.Log(vectorLibrary.UnitVector(A));
        Debug.Log(vectorLibrary.AxisAlignedReflectionX(A));
        Debug.Log(vectorLibrary.AxisAlignedReflectionY(B));
        Debug.Log(vectorLibrary.CrossProduct(A, B));
    }

    // Update is called once per frame
    void Update()
    {

    }
}
