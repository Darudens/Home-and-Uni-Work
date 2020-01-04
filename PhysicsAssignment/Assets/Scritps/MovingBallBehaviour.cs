using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovingBallBehaviour : MonoBehaviour
{
    public ArenaScript ArenaScript;
    static VectorLibrary vectorLibrary;
    public Vector3 Position;
    public Vector3 Velocity;
    public float mass;
    public float friction;
    float Radius;
    Vector3 translatevector;
    Vector3 CousionPosition;
    GameObject BottomCousion;
    GameObject TopCousion;
    GameObject TopRightCousion;
    GameObject TopLeftCousion;
    GameObject RightCousion;
    GameObject LeftCousion;
    GameObject BottomRightCousion;
    GameObject BottomLeftCousion;
    // Start is called before the first frame update
    void Start()
    {
        Position = transform.position;
        translatevector = new Vector3(1.65f, -1.17f, 0.05f);
        Radius = Mathf.Sqrt(Mathf.Pow(transform.localScale.x, 2.0f) + Mathf.Pow(transform.localScale.y, 2.0f));
        TopCousion = GameObject.Find("Cube (2)");
        TopRightCousion = GameObject.Find("Cube (3)");
        TopLeftCousion = GameObject.Find("Cube (1)");
        RightCousion = GameObject.Find("Cube (4)");
        LeftCousion = GameObject.Find("Cube");
        BottomRightCousion = GameObject.Find("Cube (5)");
        BottomLeftCousion = GameObject.Find("Cube (7)");
        BottomCousion = GameObject.Find("Cube (6)");
        vectorLibrary = new VectorLibrary();
        //Debug.Log(Radius);
    }

    // Update is called once per frame
    void Update()
    {
        RollBall();
        UpdateVelocity();
        DistanceToBoundries(Position, BottomCousion.transform.position, 0.5f);
    }
    
    void UpdateVelocity()
    {
        Velocity.x -= friction * Time.deltaTime;
        Velocity.z -= friction * Time.deltaTime;

        if(Velocity.x <= 0)
        {
            Velocity.x = 0;
        }
        if(Velocity.z <= 0)
        {
            Velocity.z = 0;
        }
    }

    void RollBall()
    {
        Position.x += Velocity.x * Time.deltaTime;
        Position.z += Velocity.z * Time.deltaTime;
        transform.position = Position;
    }

    private float DistanceToBoundries(Vector3 BallPosition, Vector3 ObjectBoundries, float HalfOfBoundry)
    {
        float Allowance = 0.0f;
        if (vectorLibrary.VectorDotProduct(BallPosition, ObjectBoundries) < - HalfOfBoundry) 
        { 
            Allowance = vectorLibrary.VectorDotProduct(BallPosition, ObjectBoundries) + HalfOfBoundry; 
        }
        else if (vectorLibrary.VectorDotProduct(BallPosition, ObjectBoundries) > HalfOfBoundry) 
        { 
            Allowance = vectorLibrary.VectorDotProduct(BallPosition, ObjectBoundries) - HalfOfBoundry; 
        }
        Debug.Log(Allowance);
        return Allowance;
    }

    private float CheckDistance(Vector3 BallPosition, Vector3 HalfOfBoundry, Transform Boundries)
    {
        Vector3 distanceDifference = vectorLibrary.SubtractTwoVectors(BallPosition, Boundries.position);
        float rightResult = Mathf.Pow(DistanceToBoundries(distanceDifference, Boundries.right, HalfOfBoundry.x), 2);
        float upResult = Mathf.Pow(DistanceToBoundries(distanceDifference, Boundries.up, HalfOfBoundry.y), 2);
        float leftResult = Mathf.Pow(DistanceToBoundries(distanceDifference, Boundries.forward, HalfOfBoundry.z), 2);
        return Mathf.Sqrt(rightResult + upResult + leftResult);
    }

    public bool CheckCollision(Vector3 BallPosition, float BallRadius, Transform boundaries, Vector3 halfOfBoundary)
    {
        if (CheckDistance(BallPosition, halfOfBoundary, boundaries) <= BallRadius) 
        { 
            return true; 
        }
        return false;
    }

}
