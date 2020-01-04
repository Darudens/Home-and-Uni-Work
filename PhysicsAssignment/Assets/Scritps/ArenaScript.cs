using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArenaScript : MonoBehaviour
{
    public Vector3 AreanaPosition;

    private void Start()
    {
        AreanaPosition = transform.position;
    }
}
