using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class MovingBallBehaviour : MonoBehaviour
{
    static VectorLibrary vectorLibrary;
    public Vector3 Position;
    public Vector3 Velocity;
    public float mass;
    public float friction;
    float Radius;
    Vector3 translatevector;
    GameObject BottomCousion;
    public GameObject[] EdgesAxisAligned;
    public GameObject[] EdgesAxisNonAligned;
    // Start is called before the first frame update
    void Start()
    {
        Position = transform.position;
        translatevector = new Vector3(1.65f, -1.17f, 0.05f);
        Radius = Mathf.Sqrt(Mathf.Pow(transform.localScale.x, 2.0f) + Mathf.Pow(transform.localScale.y, 2.0f));
        BottomCousion = GameObject.Find("Cube (2)");
        vectorLibrary = gameObject.AddComponent<VectorLibrary>();

    }

    // Update is called once per frame
    void Update()
    {
        RollBall();
        //UpdateVelocity();
        CheckWallCollisionAxisAligned();
        //CheckWAllCollisionAxisNotAligned();
    }
    
    void UpdateVelocity()
    {
        Velocity.x -= friction * Time.deltaTime;
        Velocity.z -= friction * Time.deltaTime;
    }

    void RollBall()
    {
        Position.x += Velocity.x * Time.deltaTime;
        Position.z += Velocity.z * Time.deltaTime;
        transform.position = Position;
    }

    Vector3 VectorReflection(Vector3 A, Vector3 Wall)
    {
        Vector3 Velocity;
        Wall = Wall.normalized;
        Velocity = A - (vectorLibrary.ScalarMultiplication(Wall.normalized, 2) * vectorLibrary.VectorDotProduct(Wall.normalized, A));
        return Velocity;
    }

    void CheckWallCollisionAxisAligned()
    {
        if(Position.x - EdgesAxisAligned[1].transform.position.x + 
            transform.localScale.x / 2 - EdgesAxisAligned[1].transform.localScale.z <= transform.localScale.x / 2)
        {
            Velocity.x = -Velocity.x;
        }
        if(Position.x - EdgesAxisAligned[0].transform.position.x + 
            transform.localScale.x / 2 - -EdgesAxisAligned[0].transform.localScale.z >= transform.localScale.x / 2)
        {
            Velocity.x = -Velocity.x;
        }
        if(Position.z - EdgesAxisAligned[3].transform.position.z +
            transform.localScale.x / 2 - EdgesAxisAligned[3].transform.localScale.z <= transform.localScale.x / 2)
        {

            Velocity.z = -Velocity.z;
        }
        if (Position.z - EdgesAxisAligned[2].transform.position.z +
             transform.localScale.x / 2 - -EdgesAxisAligned[2].transform.localScale.z >= transform.localScale.x / 2)
        {

            Velocity.z = -Velocity.z;
        }
    }

    //void CheckWAllCollisionAxisNotAligned()
    //{
    //    if(Position.x - EdgesAxisNonAligned[0].transform.position.x +
    //        transform.localScale.x / 2 - EdgesAxisNonAligned[0].transform.localScale.z <= transform.localScale.x / 2 
    //        && Position.z - EdgesAxisNonAligned[0].transform.position.z +
    //        transform.localScale.x / 2 - EdgesAxisNonAligned[0].transform.localScale.z <= transform.localScale.x / 2)
    //    {
    //        Velocity.x = -Velocity.x;
    //        Velocity.z = -Velocity.z;
    //    }
    //    if (Position.x - EdgesAxisNonAligned[2].transform.position.x +
    //         transform.localScale.x / 2 - EdgesAxisNonAligned[2].transform.localScale.z >= transform.localScale.x / 2
    //         && Position.z - EdgesAxisNonAligned[2].transform.position.z +
    //         transform.localScale.x / 2 - EdgesAxisNonAligned[2].transform.localScale.z >= transform.localScale.x / 2)
    //    {
    //        Velocity.x = -Velocity.x;
    //        Velocity.z = -Velocity.z;
    //    }
    //    if(Position.x - EdgesAxisNonAligned[1].transform.position.x +
    //        transform.localScale.x / 2 - EdgesAxisNonAligned[1].transform.localScale.z <= transform.localScale.x / 2
    //        && Position.z - EdgesAxisNonAligned[1].transform.position.z +
    //        transform.localScale.x / 2 - EdgesAxisNonAligned[1].transform.localScale.z <= transform.localScale.x / 2)
    //    {
    //        Velocity.x = -Velocity.x;
    //        Velocity.z = -Velocity.z;
    //    }
    //    if (Position.x - EdgesAxisNonAligned[3].transform.position.x +
    //         transform.localScale.x / 2 - EdgesAxisNonAligned[3].transform.localScale.z >= transform.localScale.x / 2
    //         && Position.z - EdgesAxisNonAligned[3].transform.position.z +
    //         transform.localScale.x / 2 - EdgesAxisNonAligned[3].transform.localScale.z >= transform.localScale.x / 2)
    //    {
    //        Velocity.x = -Velocity.x;
    //        Velocity.z = -Velocity.z;
    //    }
    //}
}
