using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallPhysics : MonoBehaviour
{
    public CubeScript cubeScript;
    public Vector3 BallPositon;
    public Vector3 GravityVector = new Vector3(0, -9.81f, 0);
    public Vector3 Velocity = new Vector3(0, 1.0f, 0);
    public Vector3 CubePos;
    public float E;
    const float bounceDistance = .8f;
    // Start is called before the first frame update
    void Start()
    {
        BallPositon = transform.position;
        CubePos = cubeScript.CubePosition;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        UpdateGravity();
        Bounce();
        UpdatePosition();
        //Debug.Log(BallPositon.y);
    }

    void Bounce()
    {
        if (BallPositon.y <= bounceDistance && Velocity.y > 0)
        {
            Velocity.y = -Velocity.y * E;
        }
        if (BallPositon.y < bounceDistance && Mathf.Abs(Velocity.y) < 0.7f)
        {
            Velocity.y = 0;
        }
        Debug.Log((Velocity.y < 0 ? "UP" : "DOWN") + " vy=" + (int)(100 * Velocity.y) / 100f + " py=" + (int)(100 * BallPositon.y) / 100f);
    }

    void UpdateGravity()
    {
        Velocity.y -= (GravityVector.y) * Time.fixedDeltaTime;
    }

    void UpdatePosition()
    {
        BallPositon.x -= Velocity.x;
        BallPositon.y -= Velocity.y;
        BallPositon.z -= Velocity.z;
        transform.position = BallPositon;
    }
}
