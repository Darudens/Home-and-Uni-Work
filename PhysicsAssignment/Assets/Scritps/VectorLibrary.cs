using UnityEngine;

public class VectorLibrary : MonoBehaviour
{

    public Vector3 VectorA;
    public Vector3 VectorB;

    private void Start()
    {
        AddTwoVectors(VectorA, VectorB);
        VectorMagnitude(VectorA);
    }

    private void Update()
    {
        
    }
    public Vector3 AddTwoVectors (Vector3 V1, Vector3 V2)
    {
        Vector3 AdditionResult = new Vector3();
        AdditionResult.x = V1.x + V2.x;
        AdditionResult.y = V1.y + V2.y;
        AdditionResult.z = V1.z + V2.z;
        Debug.Log(AdditionResult);
        return AdditionResult;
    }
    
    public Vector3 SubtractTwoVectors (Vector3 V1, Vector3 V2)
    {
        Vector3 SubtractionResult = new Vector3();
        SubtractionResult.x = V1.x + V2.x;
        SubtractionResult.y = V1.y + V2.y;
        SubtractionResult.z = V1.z + V2.z;
        Debug.Log(SubtractionResult);
        return SubtractionResult;
    }

    public float VectorDotProduct(Vector3 V1, Vector3 V2)
    {
        Vector3 DotProduct = new Vector3();
        DotProduct.x = V1.x * V2.x;
        DotProduct.y = V1.y * V2.y;
        DotProduct.z = V1.z * V2.z;
        float Result = DotProduct.x + DotProduct.y + DotProduct.z;
        Debug.Log(Result);
        return Result;
    }

   public float VectorMagnitude(Vector3 V1)
    {
        V1.x = V1.x / Mathf.Sqrt(Mathf.Pow(V1.x, 2) + Mathf.Pow(V1.y, 2) + Mathf.Pow(V1.z, 2));
        V1.y = V1.y / Mathf.Sqrt(Mathf.Pow(V1.x, 2) + Mathf.Pow(V1.y, 2) + Mathf.Pow(V1.z, 2));
        V1.z = V1.z / Mathf.Sqrt(Mathf.Pow(V1.x, 2) + Mathf.Pow(V1.y, 2) + Mathf.Pow(V1.z, 2));
        float Result = V1.x + V1.y + V1.z;
        Debug.Log(Result);
        return Result;
    }

    public Vector3 UnitVector(Vector3 V1)
    {
        V1.x = V1.x / VectorMagnitude(V1);
        V1.y = V1.y / VectorMagnitude(V1);
        V1.z = V1.z / VectorMagnitude(V1);
        Debug.Log(V1);
        return V1;
    }
}
